import numpy as np
import matplotlib.pyplot as plt

x = np.load(r"D:\UMich\Courses\EECS 598\Project\T4Train-master-Final_11_21_2021\T4Train-master-Final\T4Train-master\tmp\training_data_no_touch.npy")

instances = x.shape[1]
samples = x.shape[0]
vib,mic = 0,1

x_mic = x[:,:,mic,:]
x_mic2 = (x_mic-32768)^2

x_vib = x[:,:,vib,:]
x_vib2 = (x_vib-32768)^2

plt.figure(figsize=(10, 10))
for i in range(instances):
    ax = plt.subplot(3, 3, i + 1)
    plt.plot(x_mic[0,i,1:1500])

plt.figure(figsize=(10, 10))
for i in range(instances):
    ax = plt.subplot(3, 3, i + 1)
    plt.plot(x_mic2[0,i,1:1500])

plt.figure(figsize=(10, 10))
for i in range(instances):
    ax = plt.subplot(3, 3, i + 1)
    plt.plot(x_vib[0,i,1:1500])
