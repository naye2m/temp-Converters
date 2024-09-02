def convertTemperature(temp:float,f:str,t:str) ->float:
    """sumary_line
    
    Keyword arguments:
    temp -- temperature in current format
    f -- current/given temperature format
    t -- targeted temperature formate 
    Return: converted to t(terget) typed temp unit
    """
    
    if f == t:
        return temp
    
    match f:
        case "f": 
        # case "F":
            temp = (temp - 32) * 5.0 / 9.0 # Convert Fahrenheit to Celsius
        case "k":
            temp -= 273.15 # Convert Kelvin to Celsius
         #'c' (Celsius) requires no conversion
    
    match t:
        case "f":
            return temp * 9.0 / 5.0 + 32 #Convert Celsius to Fahrenheit
        case "k":
            return temp + 273.15 #Convert Celsius to Kelvin
         #'c' (Celsius) requires no conversion
    return temp

def getFloat(s:str,func=input)->float:
    while True:
        try:
            res:float = float(func(s or "enter float\t:\t"))
            return res
        except:
            pass
TemperatureTypes = ["f","c","k"]
def getTemperatureType(s:str,func=input)->float:
    while True:
        res:float = func(s or "enter Temp[f|c|k]\t:\t")
        if res not in TemperatureTypes:
            continue
        return res
def printTemperature(*args):
    try:
        print(convertTemperature(*args),args[2])
    except:
        print("something went wrong!")
def main():
    import sys
    def exitPrintingUsage():
        sys.exit("Usage: %s temp:float from:STR[f|k|c] to:STR[f|k|c] \nUsage: %s input" % (5,sys.argv[0],sys.argv[0]))
    if len(sys.argv) != 4 and sys.argv[1] != "input":
        exitPrintingUsage() 
    try:
        if sys.argv[1] == "input":
            args = [None] * 3
            args[1] = getTemperatureType("Enter input unit (f/c/k):\n")
            args[0] = getFloat("Enter temperature value in %s:\n" % args[1])
            args[2] = getTemperatureType("Enter desired output unit (f/c/k):\n")
            printTemperature(*args)
        else:
            printTemperature(float(sys.argv[1]),sys.argv[2],sys.argv[3])
    except:
        exitPrintingUsage()
if __name__ == "__main__":
    main()