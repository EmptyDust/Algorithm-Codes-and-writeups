def solve(t):
    mapping = {
        'A': '∧', 'B': '|3', 'C': '(', 'D': '|)', 'E': '3', 'F': '+',
        'G': '6', 'H': '|-|', 'I': '|', 'J': '_|', 'K': '|<', 'L': '|_',
        'M': '|\\/|', 'N': '|\\|', 'O': '0', 'P': '|°', 'Q': '(,)',
        'R': '|?', 'S': '$', 'T': '7', 'U': '|_|', 'V': '\\/', 'W': '\\/\\/',
        'X': '><', 'Y': '-/', 'Z': '2',
        'a': '∧', 'b': '|3', 'c': '(', 'd': '|)', 'e': '3', 'f': '+',
        'g': '6', 'h': '|-|', 'i': '|', 'j': '_|', 'k': '|<', 'l': '|_',
        'm': '|\\/|', 'n': '|\\|', 'o': '0', 'p': '|°', 'q': '(,)',
        'r': '|?', 's': '$', 't': '7', 'u': '|_|', 'v': '\\/', 'w': '\\/\\/',
        'x': '><', 'y': '-/', 'z': '2'
    }
    
    rmap = {}
    for char, trash in mapping.items():
        if trash not in rmap:
            rmap[trash] = []
        rmap[trash].append(char)
    
    i = 0
    n = len(t)
    result = 1
    MOD = 10**9
    
    while i < n:
        matched = False
        for length in range(min(4, n - i), 0, -1):
            substring = t[i:i+length]
            if substring in rmap:
                # Found a match
                count = len(rmap[substring])
                result = (result * count) % MOD
                i += length
                matched = True
                break
        
        if not matched:
            return 0
    
    return result

t = input().strip()

answer = solve(t)
print(answer)