import matplotlib.pyplot as plt
import numpy as np

# Data for current and new processes
current_steps = [
    "Dev creates ticket", "Expert reviews ticket", "Expert reviews UI changes",
    "Expert approves/rejects PR", "Dev reworks page", "New ticket raised",
    "Different expert reviews new ticket", "Expert recommends changes"
]
current_times = [1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 1.5, 0.5]

new_steps = [
    "Dev creates product & runs tool", "Tool generates reports",
    "Dev makes changes & sends PR", "Tester uses tool to test"
]
new_times = [0.25, 0.1, 1.0, 0.6]

# Combine and align data
all_steps = current_steps + new_steps
process_labels = ['Current'] * len(current_steps) + ['New'] * len(new_steps)
times = current_times + new_times

# Create bar positions and colors
y_pos = np.arange(len(all_steps))
colors = ['royalblue' if label == 'Current' else 'darkgreen' for label in process_labels]

# Plotting
plt.figure(figsize=(12, 8))
plt.barh(y_pos, times, color=colors)
plt.yticks(y_pos, all_steps)
plt.xlabel('Time Taken (hours)')
plt.title('Comparison of Time Taken: Current vs New Process')
# Add legend manually
handles = [plt.Rectangle((0,0),1,1,color='royalblue'), plt.Rectangle((0,0),1,1,color='darkgreen')]
plt.legend(handles, ['Current Process', 'New Process'])
plt.tight_layout()
plt.show()