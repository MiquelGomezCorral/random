import argparse

def mimificator(args):
    text = args.text
    vowel = args.vowel
    print("text: ", text)
    print("vowel: ", vowel)
    for vowel in ['a','e','i','o','u']:
        text = text.replace(vowel, args.vowel)
    
    print("\nAnswer:") 
    print(text)
    return text

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='Gets a text and converst all its vowels into the vowel you ask for (a,e,i,o,u)',
        description='Gets a text and converst all its vowels into the vowel you ask for (a,e,i,o,u)',
        # epilog="Make sure the data is created with 'script_train_calidad'.\nUse '--force_retrain True' to overide (if exits) an already trained model with the same name"
    )
    
    parser.add_argument('-t', '--text', default=None) 
    parser.add_argument('-v', '--vowel', default=None) 
    
    args = parser.parse_args()
    
    mimificator(args)
    