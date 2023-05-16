#! /usr/bin/python

# START 3 MARS 2022

import json
import subprocess
import numpy as np
import matplotlib.pyplot as plt

fig, (ax1, ax2) = plt.subplots(1, 2)


cmd = 'watson report -j -a'
process = subprocess.Popen(cmd.split(' '),
                     stdout=subprocess.PIPE,
                     stderr=subprocess.PIPE)
stdout, stderr = process.communicate()

d = json.loads(stdout)

by_project = {}
by_tag = {}

for project in d["projects"]:
    total = 0
    for tag in project["tags"]:
        if tag["name"] == "holiday":
            continue

        if tag["name"] not in by_tag:
            by_tag[tag["name"]] = 0
        time_h = round(tag["time"]/60/60)

        total += time_h
        by_tag[tag["name"]] += time_h

    by_project[project["name"]] = total

values = []
labels = []
for p in by_project:
    values.append(by_project[p])
    labels.append(p)

# plt.subplot(1, 2, 1)
ax1.pie(values, labels=labels, textprops={'color':"w"})

values = []
labels = []
for t in by_tag:
    values.append(by_tag[t])
    labels.append(t)

values_filter = [0]
labels_filter = ["autres"]

for i, v in enumerate(values):
    if v < 10:
        values_filter[0] += v
    else:
        values_filter.append(v)
        labels_filter.append(labels[i])

# plt.subplot(1, 2, 2)
ax2.pie(values_filter, labels=labels_filter, textprops={'color':"w"})

# plt.subplots_adjust(left=0.1,
#                     bottom=0.1,
#                     right=0.9,
#                     top=0.85,
#                     wspace=0.4,
#                     hspace=0.4)

fig.suptitle('Répartition du temps depuis le 03/03/2022', fontdict = {'color':'white'})
fig.tight_layout()
fig.savefig("/tmp/w2d", transparent=True)

cmd = 'tycat /tmp/w2d.png'
subprocess.call(cmd.split(' '))
