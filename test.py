import numpy as np
import os
import sys
import pandas as pd
import matplotlib.pyplot as plt


def simple_burst_duration (data):
	v = data[:,0]
	times = []
	events = []
	flag = 0

	if np.isnan(v).any():
		return -2

	maxv = max(v)
	minv = min(v)
	r = maxv - minv

	for i in range(len(v)):
		if (v[i] > (minv + r*0.9) and flag == 1):
			flag = 0
			times.append(i)
			events.append(v[i])
		elif (v[i] < (minv + r*0.1) and flag == 0):
			flag = 1

	intr = inter_burst_pts(times)

	plt.plot(v)
	plt.plot(times, events, 'o')
	plt.show()

	if not intr:
		return -1
	else:
		return np.mean(intr)



def inter_burst_pts (times):
	inter = []
	if not times:
		return inter

	old = times[0]

	for i in range(1, len(times)):
		inter.append(times[i] - old)
		old = times[i]


	return inter




model_name = sys.argv[1]
method = int(sys.argv[2])
dt = float(sys.argv[3])


print("Method %d"%(method))


filename = "model_library/neuron/"+model_name+"/output_"+str(method)+"_"+str(dt)+".txt"

# Calculate model
os.system("make FOLDER="+model_name+" MODEL="+model_name.lower()+"")
os.system("./model_library/neuron/"+model_name+"/"+model_name.lower()+" "+filename+" "+str(method)+" "+" "+str(dt)+"")

try:
	dataset = pd.read_csv(filename, delimiter=' ')
	data = dataset.values

	plt.plot(data[:,0])
	plt.show()

	dur = simple_burst_duration(data)
	print(dur)
except:
	empty_file = 1
finally:
	os.system("rm "+filename)
	os.system("make FOLDER="+model_name+" MODEL="+model_name.lower()+" clean")



