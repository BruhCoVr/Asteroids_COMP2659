'''
    Add the following text files.

    input.txt -> binary input
    output.txt -> hex output
'''

END_TEXT_WITH = "," # Change to 'L,' when dealing with widths >= 32 bits
NUMBER_OF_COLUMNS = 4 # 

quickHex = {
    "0000" : "0",
    "0001" : "1",
    "0010" : "2",
    "0011" : "3",
    "0100" : "4",
    "0101" : "5",
    "0110" : "6",
    "0111" : "7",
    "1000" : "8",
    "1001" : "9",
    "1010" : "A",
    "1011" : "B",
    "1100" : "C",
    "1101" : "D",
    "1110" : "E",
    "1111" : "F",


}

def binaryToHexadecimal(n):
    text = ""
    new = n.replace('\n', '')
    for i in range(len(n)//4):
        sil = new[-4:]
        new = new[:-4]
        sil = (4-len(sil))*"0" + sil
        text = quickHex[sil] + text
    return text

def main():
    inputFile = open("input.txt","r")
    outputFile = open("output.txt","w")
    counter = 0
    for line in inputFile:
        
        while (True):
            # Section each line into 32 bit max
            section = line[:32]
            line = line[32:]

            # Write hex to output file
            outputFile.write("0x" + binaryToHexadecimal(section) + END_TEXT_WITH)

            # Formatting
            counter += 1
            if (counter == NUMBER_OF_COLUMNS):
                outputFile.write("\n")
                counter = 0

            if (len(line) < 32): # Simulate do while
                break

    inputFile.close()
    outputFile.close()

main() 
