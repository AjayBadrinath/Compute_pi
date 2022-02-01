import random as r
import math
import numpy as np
import matplotlib.pyplot as plt
lx,ly=[],[]
def compute_pi(sample_points):
    inside_point_ctr=0
    for i in range(sample_points):
        x=r.random()
        y=r.random()
        lx.append(x)
        ly.append(y)
        if(math.sqrt(x**2+y**2)<=1):inside_point_ctr+=1
    return 4*inside_point_ctr/sample_points        
def draw():
    x_axis=np.linspace(0,1.0,150)
    y_axis=np.linspace(0,1.0,150)
    a,b=np.meshgrid(x_axis,y_axis)
    circle_equation=a**2+b**2-1.0
    _,axis=plt.subplots()
    axis.contour(a,b,circle_equation,[0])
    plt.scatter(lx,ly,s=0.001)
    axis.set_aspect(1)
    plt.title("Scatter Plot of Points sampled")
    plt.show()
sample_point=int(input("Enter the number of sample points to compute pi->Enter a large value 10000<x<10000000"))
flag='y'
if sample_point>10000000:
    flag=input("This value is much above the limit .Allowing this process may hog your memory .Do you still want to proceed?[y/n]")
if flag=='y':    
    print("The Computation may take seconds to compute Please wait")
    print("Value of Pi (approximated): ",compute_pi(sample_point))
    draw()
else:
    exit()
