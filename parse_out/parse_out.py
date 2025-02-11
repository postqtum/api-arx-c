import sys
import re

file_path = sys.argv[1]

lines = open(file_path, 'r').readlines()

# signature name into objects list
name2prjs = dict()
selected = set()
SEL_PRJ = 'ARX.22.x64'

current_project = ''
for line in lines:
    # broken reference found
    match = re.search(r'unresolved external symbol "([^"]+)"', line)
    if match:
        key = match.groups()[0]
        if current_project == SEL_PRJ:
            selected.add(key)
        else:
            if key in name2prjs.keys():
                name2prjs[key].append(current_project)
            else:
                name2prjs[key] = [current_project]
        continue
    # project line found
    match = re.search(r'------ Build started: Project: ([^,]+),', line)
    if match:
        current_project = match.groups()[0]
        continue

# remove duplicates from lists using sets
values = name2prjs.values()
idx = 0
while idx < len(values):
    values[idx] = list(set(values[idx]))
    idx += 1

# sort by number of references
zipped = zip(name2prjs.keys(), values)
stded = reversed(sorted(zipped, key=lambda x: len(x[1])))

outf = sys.stdout
if (len(sys.argv) > 2):
    outf = open(sys.argv[2], "w")

# print list
NUM_THR = 4
for pair in stded:
    arr = pair[1]
    is_selected = False
    if pair[0] in selected:
        is_selected = True
        selected.remove(pair[0])
    if len(arr) > NUM_THR:
        outf.write(pair[0] + ' ' + ('*OpenDCL* ' if is_selected else '') + str(arr[:NUM_THR])[:-1] + ' and ' + str(len(arr) - NUM_THR) + ' others]\n')
    else:
        outf.write(pair[0] + ' ' + ('*OpenDCL* ' if is_selected else '') + str(arr) + '\n')

outf.write(str(len(selected)) + ' dependencies were not found\n')

for key in selected:
    outf.write(key + ' *OpenDCL*\n')

if (len(sys.argv) > 2):
    outf.close()