# Data Engineering and Analysis with GitHub Copilot

## Exercises

The goal of these exercises is to use GitHub Copilot to help load, clean, analyze, and test data related to [Punxsutawney Phil's](https://en.wikipedia.org/wiki/Punxsutawney_Phil) predictions and subsequent weather conditions.

**Dataset:** `punxsutawney_phil.csv`

**Main Script:** `phil_analysis.py`
**Test Script:** `test_phil_analysis.py`

---

### Exercise 1: Setup and First Completions

**Goal:** Load the dataset using Pandas and perform initial inspections, letting Copilot assist with basic code completion.

**General Tips:**

- Use comments to describe what you want to do.
- Add the columns of your table (i.e. output of `df.info()`) to your prompt to help Copilot understand the context.

**Tasks:**

1.  Open `phil_analysis.py`.
2.  First, load the data. Type `# Load the dataset from punxsutawney_phil.csv` and accept or adapt Copilot's suggestion, likely `df = pd.read_csv('punxsutawney_phil.csv')`.
3.  Let's look at the data. Type `# Display the last 10 rows` and accept the suggestion for `print(df.tail(10))`.
4.  Check the data types and non-null counts. Type `# Print dataframe info` and accept the suggestion for `print(df.info())`.
5.  Make sure that the Temperature columns are numeric types.
6.  Run the script (`python phil_analysis.py`) to ensure it loads the data correctly and prints the information.

---

### Exercise 2: Data Cleaning and Transformation with Completions

**Goal:** Clean the data, handle missing values, and create a standardized prediction column using Copilot's inline suggestions.

**Tasks:**

1.  Phil's predictions are varied ('Full Shadow', 'No Shadow', 'Partial Shadow', 'No Record'). Let's simplify this. A common interpretation is "Full Shadow" means 6 more weeks of winter ("Long Winter"), while "No Shadow" (and often "Partial Shadow") means an early spring ("Early Spring").
    Type the following comment and let Copilot generate the logic:
    ```python
    # Create a 'Simplified Prediction' column based on 'Punxsutawney Phil'
    # 'Full Shadow' maps to 'Long Winter'
    # 'No Shadow' or 'Partial Shadow' maps to 'Early Spring'
    # 'No Record' maps to 'Unknown'
    ```
    _(Self-Correction: Review Copilot's suggestion. Does it handle all cases correctly? Does it use `.map`, `.apply`, or `np.select`? Ensure it aligns with the logic described.)_
2.  Change the temperature columns from Fahrenheit to Celsius using Github Copilot.
    _hint_: Use 'in the columns that contain "Temperature"' in your prompt.
    _(Self-Correction: Review Copilot's suggestion. Does it handle NaN values? Is the conversion correct?)_
3.  There are a few missing values in the dataset. We can drop the rows, or we can impute them. Choose one of the following:
    - Drop rows with missing values.
    - Fill missing values with the mean or median of the column.
    - Use forward fill or backward fill methods.
4.  Standardize the column names to be snake_case. For example, 'February Average Temperature (Pennsylvania)' should become 'february_average_temperature_pennsylvania'.
    \*(Self-Correction: Review Copilot's suggestion. Does it handle all cases? Are the new column names clear and consistent?)\_
5.  We also want to add a column that calculates the difference between February and March temperatures. Make separate columns for the total, northeast, midwest and pensylvania differences. This will be helpful for our accuracy check later.
    _(Self-Correction: Review Copilot's suggestion. Did you get three separate columns? Is the calculation correct?)_
6.  Inspect the results. Print a few values, analyze the value counts of the simplified prediction column, and check the DataFrame info again.

---

### Exercise 3: Defining Accuracy with Copilot Chat

**Goal:** Use Copilot Chat to define a function that determines if Phil's prediction was "correct" based on subsequent temperatures, potentially incorporating external data.

**Tasks:**

1.  **Define "Accuracy":** Let's define a simple accuracy rule:

    - If Phil predicted 'Long Winter', was March significantly colder or similar than February?
    - If Phil predicted 'Early Spring', was March warmer than February?
    - We'll focus on the _Pennsylvania_ temperatures for simplicity. Let's define "significantly colder or similar" as March being lower than 3 degree Celsius colder than February, and "warmer" as March being warmer than Feb by any amount higher than 3 degrees Celsius.

2.  **Use Copilot Chat:**

    - Open the Copilot Chat panel.
    - Finish the following prompt (adjust based on your exact column names if needed):

      ```
      Write a Python function called `check_prediction_accuracy` that takes a single row...
      ```

      Include the logic for checking the prediction accuracy based on the rules defined above. The function should return:

      - `True` if the prediction was correct,
      - `False` if it was incorrect,
      - `None` if the prediction is 'Unknown' or if any temperature data is missing.

    - Ask Copilot Chat how to apply this function to create a new 'prediction_correct' column.

3.  **Analyze Results:** Ask Copilot to display the results of the accuracy check in a graph. Here are a few possible graphs you could create:
    - A bar chart showing the count of correct vs incorrect predictions.
    - A line graph showing the rolling average accuracy over the years.
    - A scatter plot comparing February and March temperatures with color coding for predictions.
    - A histogram of the temperature differences for each prediction type.
    - Try something yourself!

---

### Exercise 4: Refactoring, Optimization, and Synthetic Data

**Goal:** Use Copilot to refactor the accuracy calculation for potential performance improvement and readability. We also take a step into generating synthetic data.

**Tasks:**

1.  **Refactoring `.apply()`:** The `df.apply(..., axis=1)` method used in Exercise 3 can be slow on very large datasets. Let's try to vectorize it.

    - Ask Copilot Chat or use inline comments/edit features:
      ```
      Refactor the creation of the 'Accuracy' column. Instead of using .apply() with the `check_prediction_accuracy` function, use vectorized pandas/numpy operations (like np.where or boolean indexing) based on the same logic defined in the function. Handle NaN values appropriately.
      ```
    - **Pitfall:** Carefully compare the results of the vectorized approach (`df['Accuracy_vectorized'].value_counts(dropna=False)`) with the `.apply()` approach (`df['Accuracy'].value_counts(dropna=False)`). Do they produce the _exact_ same counts for True, False, and NaN? Sometimes vectorized operations handle edge cases or NaNs slightly differently. Use Copilot Chat if you see discrepancies: "Why might the results of the `.apply` method and the `np.where` method differ for calculating accuracy?"

2.  **Generating Synthetic Data:** Let's generate some fake data to potentially test our functions later.
    - Ask Copilot Chat:
      ```
      Generate a Python script using pandas and numpy to create a synthetic DataFrame called `synthetic_df` with 100 rows. It should have columns:
      - 'Year': Integers from 2000 to 2099.
      - 'Punxsutawney Phil': Randomly 'Full Shadow' or 'No Shadow'.
      - 'February Average Temperature (Pennsylvania)': Random float between 25.0 and 40.0.
      - 'March Average Temperature (Pennsylvania)': Random float between 30.0 and 50.0.
      Ensure appropriate imports for pandas and numpy.
      ```

---

### Exercise 5: Documenting the Analysis

**Goal:** Use Copilot to generate docstrings for functions and create a README file explaining the script.

**Tasks:**

1.  Generate Docstrings and inline comments
2.  **Create README:**

    - Ask Copilot Chat (you can reference your script using `#file phil_analysis.py` if your IDE supports it):

      ```
      Create a README.md file for the script `phil_analysis.py`.

      It should include:
      - A brief description: Analyzing Punxsutawney Phil's Groundhog Day predictions against historical temperature data.
      - Data Source: Mentions `punxsutawney_phil.csv`.
      - Requirements: Lists necessary libraries (pandas, numpy, pytest, requests).
      - How to Run: `python phil_analysis.py`.
      - Key Steps: Briefly outline the main steps performed (loading, cleaning, simplifying predictions, checking accuracy).
      ```

---

### Exercise 6: Testing the Logic

**Goal:** Use Copilot to generate unit tests for the data cleaning and accuracy logic using `pytest`.

**Tasks:**

1.  In the file named `test_phil_analysis.py`:
2.  Create a test function to check the data loading and cleaning process. Use Copilot to generate a test function that checks:

    - The DataFrame is loaded correctly.
    - The expected columns are present.
    - The simplified prediction column has the correct values.
    - Add tests and assertions for the previous exercises.

3.  **Run Tests:**
    - Open your terminal in the project directory.
    - Run `pytest`.
    - **Pitfall / Debugging:** If any tests fail, examine the error messages. Use Copilot Chat to help understand _why_ a test might be failing. Use the context of the failing test and the relevant function/logic from `phil_analysis.py` in Chat and ask: "This pytest test is failing. Can you help me debug the function/logic based on this test failure?" This forces interaction beyond simple generation. Did the original logic handle an edge case correctly? Did the test make a wrong assumption?

---

**Next Steps (Beyond Exercises):**

- Explore more sophisticated accuracy metrics.
- Refine the handling of missing data using different imputation techniques suggested by Copilot.
- `Show me Python code using requests and pandas to fetch data from 'https://groundhog-day.com/api/v1/groundhogs' and display the names and predictions count for each groundhog.`
