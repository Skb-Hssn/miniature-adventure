import os
import re

INPUT_DIR = "Input"
MAX_T = 10_000
MAX_N = 1_000_000
MAX_SUM_N = 1_000_000

def is_valid_line(line):
    # Check if there are extra spaces or multiple spaces
    return line == line.strip() and "  " not in line

def validate_file(filepath):
    with open(filepath, "r") as f:
        lines = [line.rstrip("\n") for line in f]

    if not lines:
        return f"{filepath}: ❌ File is empty"

    total_n = 0

    # Validate t
    if not lines[0].isdigit():
        return f"{filepath}: ❌ First line is not a valid integer"
    t = int(lines[0])
    if not (1 <= t <= MAX_T):
        return f"{filepath}: ❌ Invalid t={t}, must be in [1, {MAX_T}]"

    idx = 1
    for test_case in range(t):
        if idx + 1 >= len(lines):
            return f"{filepath}: ❌ Test case {test_case+1} incomplete"

        n_line = lines[idx]
        a_line = lines[idx + 1]

        if not is_valid_line(n_line):
            return f"{filepath}: ❌ Extra spaces in line {idx+1}: '{n_line}'"
        if not is_valid_line(a_line):
            return f"{filepath}: ❌ Extra spaces in line {idx+2}: '{a_line}'"

        # Parse n
        if not n_line.isdigit():
            return f"{filepath}: ❌ Invalid n at line {idx+1}"
        n = int(n_line)
        if not (1 <= n <= MAX_N):
            return f"{filepath}: ❌ n={n} at line {idx+1} out of bounds"

        # Parse A
        A_tokens = a_line.split()
        if len(A_tokens) != n:
            return f"{filepath}: ❌ Expected {n} integers in line {idx+2}, found {len(A_tokens)}"

        try:
            A = list(map(int, A_tokens))
        except ValueError:
            return f"{filepath}: ❌ Non-integer value in line {idx+2}"

        if any(not (0 <= a <= n) for a in A):
            return f"{filepath}: ❌ Invalid value in A at line {idx+2}, must be in [0, {n}]"

        total_n += n
        if total_n > MAX_SUM_N:
            return f"{filepath}: ❌ Cumulative n exceeds {MAX_SUM_N}"

        idx += 2

    if idx != len(lines):
        return f"{filepath}: ❌ Extra lines after last test case"

    return f"{filepath}: ✅ OK"

def main():
    if not os.path.exists(INPUT_DIR):
        print(f"❌ Folder '{INPUT_DIR}' does not exist.")
        return

    for filename in sorted(os.listdir(INPUT_DIR)):
        if filename.startswith('.'):
            continue  # Skip hidden files like .DS_Store
        path = os.path.join(INPUT_DIR, filename)
        if os.path.isfile(path):
            result = validate_file(path)
            print(result)

if __name__ == "__main__":
    main()

