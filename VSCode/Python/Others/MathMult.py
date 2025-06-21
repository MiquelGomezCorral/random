import numpy

# Page rank
MatrizPG = numpy.array(
    [[.030,.030,0.880,.030,.030],
     [.030,.880,0.030,.030,.030],
     [.030,.313,0.030,.313,.313],
     [.030,.880,0.030,.030,.030],
     [.030,.030,0.030,.030,.880]
     ]
)
startPG = numpy.array([1.0,.0,.0,.0,.0])

# HIT
MatrizHITS = numpy.array(
    [[1,0,0,1,1],
     [1,1,0,1,0],
     [1,0,0,0,1],
     [0,0,0,0,0],
     [0,0,0,0,0]]
)
startHUBS = numpy.array([1,1,1,1,1])
startAUTHORITIES = numpy.array([1,1,1,1,1])

for _ in range(6):
    print(f'{startHUBS = }')
    print(f'{startAUTHORITIES = }')
    
    
    startHUBS_Pre = startHUBS
    
    startHUBS = MatrizHITS @ startAUTHORITIES
    startAUTHORITIES = startHUBS_Pre @ MatrizHITS


