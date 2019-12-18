import time

tape = "$00000000000"
offset = 0
pointer = 0
status = 0

goals = [11]

L = -1
R = 1

rules = {
  0: {
    '0': ('0', R, 10)
  },
  1: {
    '0': ('0', R, 1),
    ' ': (' ', L, 2),
    'Y': ('Y', L, 2),
  },
  2: {
    '0': ('Y', L, 3),
    'X': ('X', R, 5)
  },
  3: {
    '0': ('0', L, 3),
    'X': ('X', R, 12)
  },
  5: {
    'Y': ('Y', R, 5),
    ' ': (' ', L, 6)
  },
  6: {
    'Y': (' ', L, 6),
    'X': ('0', L, 6),
    '$': ('$', L, 7)
  },
  7: {
    '0': ('0', L, 7),
    ' ': ('0', R, 8),
  },
  8: {
    '0': ('0', R, 8),
    '$': ('$', R, 0),
  },
  10: {
    '0': ('0', L, 12),
    ' ': (' ', R, 11),
  },
  11: {
  },
  12: {
    '0': ('X', R, 1),
    'Y': ('Y', R, 5)
  }
}

print(tape)
print(" "*(offset + pointer + 1)+"↑")
print("start at status0")
print("===============================")
time.sleep(1)

while True:
    if not (status in rules and tape[offset + pointer + 1] in rules[status]):
        if status in goals:
            print("end!")
        else:
            print("error!!")
        break
    rule = rules[status][tape[offset + pointer + 1]]
    tape = tape[:(offset + pointer + 1)] + rule[0] + tape[(offset + pointer + 2):]

    pointer += rule[1]
    if len(tape) <= offset + pointer + 1:
        tape += " "

    if 0 > offset + pointer + 1:
        tape = " " + tape
        offset += 1

    print(rule)
    print(tape)
    print(" "*(offset + pointer + 1)+"↑")
    print("go to status"+str(rule[2]))
    print("===============================")
    status = rule[2]
    time.sleep(1)
