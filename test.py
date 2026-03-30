class solution:
    def count(self,str,ch):
        c=0
        for i in range(len(str)):
            if str[i]==ch:
                c+=1
        return c

if __name__=="__main__":
    s=solution()
    # str=map(char,input().split())
    str=input()
    ch=input()
    c=s.count(str,ch)
    print(c)