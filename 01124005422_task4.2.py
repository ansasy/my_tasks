import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Load the dataset (replace 'dataset.csv' with the actual filename)
data = pd.read_csv('/content/shrink_ray_dataset.csv')

X = data['Power'].values.reshape(-1, 1)
y = data['Shrinkage'].values.reshape(-1, 1)

# Create a linear regression model
model = LinearRegression()

# Fit the model to the data
model.fit(X, y)

# Calculate R-squared on the test data
r_squared = model.score(X, y)
print("R-squared:", r_squared)

# Predict shrinkage for 85% on the moon
predicted_knob = model.predict([[moon_shrinkage]])

predicted_value = predicted_knob[0][0]  # Extract the predicted value
print("To achieve {:.2f}% shrinkage on the moon, adjust the knob to {:.2f} MW".format(moon_shrinkage, predicted_value))
# Scatter plot of the data
plt.scatter(X, y, color='blue', label='Data')
plt.xlabel('Knob (MW)')
plt.ylabel('Shrinkage Percentage')
plt.title('Shrinkage Data and Linear Model')
plt.legend()
# Plot the linear model
plt.plot(X, model.predict(X), color='red', label='Linear Model')
plt.legend()
plt.show()