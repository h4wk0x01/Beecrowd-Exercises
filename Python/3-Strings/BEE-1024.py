
'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''

lines = input()
for i in range(int(lines)):
    string = input()
    result = ''
    for char in string:
        if char >= 'A' and char <= 'Z' or char >= 'a' and char <= 'z':
            shifted_char = chr(ord(char) + 3)
            result += shifted_char;
        else:
            result += char;
    reversed_str = result[::-1] # First step, uppercase or lowercase shifted three positions to the right, line reversed
    half = int(len(reversed_str)//2)
    substring = reversed_str[0:half]
    for char in range(half,len(reversed_str)): # Second step
        shifted_char = chr(ord(reversed_str[char]) - 1)
        substring += shifted_char;
    print(substring)




