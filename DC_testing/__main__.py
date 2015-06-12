import DC1
import random



def __main__():
    print("main")
    dc = DC1.internal_DC()
    for j in range(100000):
        data = ''
        for i in range(1100):
            data = data + chr(random.randint(0,255))
        dc.store_msg((random.randint(0,5),random.randint(0,5),data))
        print j 
        
if __name__ == '__main__':
    main()