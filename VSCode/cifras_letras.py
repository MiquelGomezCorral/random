import random
import operator
from typing import Callable, Literal

# =================================================================
#                           CONFIGURATION 
# =================================================================
NUMBERS = [1,2,3,4,5,6,7,8,9,10,25,50,100]
_OPERATIONS: dict[str, Callable[[float, float], float]] = {
    "+": operator.add, 
    "-": operator.sub, 
    "*": operator.mul, 
    "/": operator.truediv,
}

class Operation:
    def __init__(self, op: Literal["+","-","*","/"]):
        self.op_str = op
        self.op = _OPERATIONS[op]

    def __call__(self, a: int, b: int):
        if self.op_str == "/" and b == 0: 
            res = float('inf')
        else:
            res = self.op(a,b)

        return res, f"{a:4} {self.op_str} {b:4} = {res:4}"
    
class OperationResult:
    def __init__(self, op: Operation, a: int, b: int):
        self.op = op
        self.a = a
        self.b = b
        self.res, self.res_srt = op(a,b)

    def __str__(self):
        return self.res_srt

        

OPERATIONS: list[Operation] = [
    Operation(op) for op in _OPERATIONS.keys() 
]


# =================================================================
#                           FUNCTIONS 
# =================================================================
def pop_copy(lst: list, idx: int) -> list:
    return lst[:idx] + lst[idx+1:]


def cifras(obj: int, nums: list[int]) -> tuple[int, int, list[OperationResult]]:
    print(f"\n\n" + "="*100)
    print(f"{'PROCESANDO...':^100}")
    return cifras_loop(obj, nums, [])


def cifras_loop(obj: int, nums: list[int], carry_ops: list[OperationResult]) -> tuple[int, int, list[OperationResult]]:
    best_res, best_diff, best_ops = -1, float('inf'), carry_ops
    for i, num_i in enumerate(nums):
        # Remove in use number
        nums_pop_i = pop_copy(nums, i) 
        for op in OPERATIONS:
            for j, num_j in enumerate(nums_pop_i):
                # Remove in use number
                res, op_str = op(num_i, num_j)
                if res < 0 or res % 1 != 0:
                    continue # Evitar operaciones con números negativos y decimales
                else: res = int(res)

                op_res = OperationResult(op, num_i, num_j)
                nums_pop_j = pop_copy(nums_pop_i, j) + [res]
                carry_ops_j = carry_ops + [op_res]
                res_dif = abs(obj - res)

                if res_dif == 0:
                    print("PERFECTO ENCONTRADO!")
                    return res, res_dif, carry_ops_j
                else:
                    carry, carry_dif, ops_carry  = cifras_loop(obj, nums_pop_j, carry_ops_j)
                    if carry_dif == 0:
                        return carry, carry_dif, ops_carry
                    elif min(res_dif, carry_dif) < best_diff:
                        if res_dif <= carry_dif:
                            best_res, best_diff, best_ops = res, res_dif, carry_ops_j
                        else:
                            best_res, best_diff, best_ops = carry, carry_dif, ops_carry
    # END for nums
    return best_res, best_diff, best_ops


def process_answer(best_ops: list[OperationResult], nums: list[int]) -> str:
    last_op = best_ops[-1]
    pre_ops: list[OperationResult] = [last_op]
    nums_to_check = [last_op.a, last_op.b]

    # print(f"{nums_to_check = }")
    while len(nums_to_check) > 0:
        base = nums_to_check.pop(0)

        for i, op in enumerate(best_ops):
            if base == op.res:
                pre_ops.append(op)
                best_ops.pop(i)
                nums_to_check += [op.a, op.b]
                break

    return list(map(str, pre_ops[::-1]))

# =================================================================
#                           MAIN 
# =================================================================
if __name__ == "__main__":
    print(f"\n\n" + "="*100)
    print(f"{'BIENVENIDO A CIFRAS Y LETRAS':^100}")
    print(f"="*100)
    print("(en verdad solo cifras...)")
    print("Este ejercicio consiste en, dado un número objetivo, usar otros cinco números para encontrar, mediante operaciones básicas enteras (+ - x /),")
    print("la forma de construir este número. Por ejemplo, dado 42 y 4, 6, 1, 10, 2 -> 10*4 = 40, 40+2=42.")
    print("Sige las instrucciones para empezar, podrás customizarlo o hacerlo aleatorio :)\n\n\n")
    
    
    
    lower, upper    = 0, 1000
    expected_cifras = 5
    randon_flag     = False


    print(f"Introduce el número objetivo (recomendable entre {lower} y {upper}).")
    print("Puedes escribir 'r' para que el número sea aleatorio.")
    print("Puedes escribir 'rr' para que todo sea aleatorio.")
    obj_input = input("> ").strip().lower()
    if obj_input in ['r', 'random', 'rr']:
        obj = random.randint(lower, upper)
        print(f"-> {obj}")
        randon_flag = obj_input == 'rr'
    else:
        obj = int(obj_input)
        assert lower <= obj <= upper, f"Número fuera de rango {[lower, upper]}"

    print("Introduce números (uno por línea). Enter vacío para finalizar")
    print("Puedes escribir 'r' para que el número sea aleatorio.")
    print("Puedes escribir 'rr' para que todo sea aleatorio.")
    nums = []
    while len(nums) < expected_cifras:
        if not randon_flag:
            val = input("> ").strip().lower()
        else:
            val = "r"
        if val == "":
            break
        if val in ['r', 'random', 'rr']:
            num = random.choice(NUMBERS)
            nums.append(num)
            randon_flag = randon_flag or (val == 'rr')
            print(f"-> {num}")
        else:
            n = int(val)
            if n in NUMBERS: 
                nums.append(n)
            else:
                print(f"Número no permitido: {', '.join(NUMBERS)}")

    print(f"OBJETIVO: {obj}")
    print(f"CIFRAS: {', '.join(map(str, nums))}")

    best_res, best_diff, best_ops = cifras(obj, nums)



    print(f"\n\n" + "="*100)
    print(f"{'RESPUESTA':^100}")
    print(f"OBJECTIVO: {obj}")
    print(f"CIFRAS: {', '.join(map(str, nums))}")
    print(f" - Mejor respuesta: {best_res:4}")
    print(f" - Con diferencia:  {best_diff:4}")

    opserations_clean = process_answer(best_ops, nums)
    print(f" - Operaciones:     {opserations_clean[0]}")
    for operation in opserations_clean[1:]:
        print(f"                    {operation}")
        