print (" the calculator")


d='y'


while (d =='y'):
    a=input("enter the number")
    b=input("enter the number")

    c=input(""" operators used:
    1 -- add
    2 -- sub
    3 -- modulus
    4 -- division
    5 -- multiply
    6 -- exit
    """)
    if (int(c)==1):
        print (int(a)+int(b))
    elif (int(c)==2):
        print (int(a)-int(b))
    elif (int(c)==3):
        print (int(a)%int(b))
    elif (int(c)==4):
        print (int(a)/int(b))
    elif (int(c)==5):
        print (int(a)*int(b))
    elif (int(c)==6):
        break
    else:
        print ("invalid")
    d=input("do you want to continue enter y to continue")
        
    
        
    
