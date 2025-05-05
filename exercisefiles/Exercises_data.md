# Goal

The goal is to create a HTTPServer using the language of your choice. You can find language dependent information in the README.md file in the language folder.

Follow the instructions below and try to use GitHub Copilot as much as possible.
Try different things and see what GitHub Copilot can do for you, like generating a class, add comments, tests or a Docker file.

> First, follow the [pre-requisites.md](../README.md#pre-requisites) to setup GitHub Copilot for your IDE.

## Exercises

The goal of these exercises is to use GitHub Copilot to help load, clean, analyze, and test data related to [Punxsutawney Phil's](https://en.wikipedia.org/wiki/Punxsutawney_Phil) predictions and subsequent weather conditions.

**Dataset:** `punxsutawney_phil.csv`

**Main Script:** `phil_analysis.py`
**Test Script:** `test_phil_analysis.py`

---

### Exercise 1: Setup and First Completions

**Goal:** Load the dataset using Pandas and perform initial inspections, letting Copilot assist with basic code completion.

**Tasks:**

1.  Open `phil_analysis.py`.
2.  First, load the data. Type `# Load the dataset from punxsutawney_phil.csv` and accept or adapt Copilot's suggestion, likely `df = pd.read_csv('punxsutawney_phil.csv')`.
3.  Let's look at the data. Type `# Display the last 10 rows` and accept the suggestion for `print(df.tail(10))`.
4.  Check the data types and non-null counts. Type `# Print dataframe info` and accept the suggestion for `print(df.info())`.
5.  Run the script (`python phil_analysis.py`) to ensure it loads the data correctly and prints the information.

---

### Exercise 2: Data Cleaning and Transformation with Completions

**Goal:** Clean the data, handle missing values, and create a standardized prediction column using Copilot's inline suggestions.

**Tasks:**

1.  In `phil_analysis.py`, below the loading code, notice from `df.info()` that temperature columns might be loaded as 'object' type if they contain non-numeric data (like blanks). We need them as numbers. Type:

    ```python
    # Identify temperature columns (those containing 'Temperature')
    # Let Copilot suggest how to get a list of these column names.
    # Example starting point: temp_cols = [col for col in df.columns if 'Temperature' in col]
    # (Accept or modify Copilot's suggestion)

    # Convert temperature columns to numeric, coerce errors to NaN
    # for col in temp_cols:
        # Start typing the conversion logic, e.g., df[col] = pd.to_numeric(
        # Let Copilot complete the line with errors='coerce'
    ```

2.  Phil's predictions are varied ('Full Shadow', 'No Shadow', 'Partial Shadow', 'No Record'). Let's simplify this. A common interpretation is "Full Shadow" means 6 more weeks of winter ("Long Winter"), while "No Shadow" (and often "Partial Shadow") means an early spring ("Early Spring").
    Type the following comment and let Copilot generate the logic:
    ```python
    # Create a 'Simplified Prediction' column based on 'Punxsutawney Phil'
    # 'Full Shadow' maps to 'Long Winter'
    # 'No Shadow' or 'Partial Shadow' maps to 'Early Spring'
    # 'No Record' maps to 'Unknown'
    # Hint: You might use a mapping dictionary and .map() or np.select()
    ```
    _(Self-Correction: Review Copilot's suggestion. Does it handle all cases correctly? Does it use `.map`, `.apply`, or `np.select`? Ensure it aligns with the logic described.)_
3.  Inspect the results. Type `# Show the value counts for the new simplified prediction column` and let Copilot suggest `print(df['Simplified Prediction'].value_counts())`.
4.  Re-run `df.info()` using Copilot (`# Print info again to check temperature column types`) to confirm temperature columns are now numeric (float).
5.  Run the script. Check the output for the value counts and the DataFrame info.

---

### Exercise 3: Defining Accuracy with Copilot Chat

**Goal:** Use Copilot Chat to define a function that determines if Phil's prediction was "correct" based on subsequent temperatures, potentially incorporating external data.

**Tasks:**

1.  **Define "Accuracy":** Let's define a simple accuracy rule:

    - If Phil predicted 'Long Winter', was March significantly colder than February?
    - If Phil predicted 'Early Spring', was March warmer than or similar to February?
    - We'll focus on the _Pennsylvania_ temperatures for simplicity. Let's define "significantly colder" as March being at least 1 degree Fahrenheit colder than February, and "warmer or similar" as March being warmer than Feb by any amount, or colder by less than 1 degree.

2.  **Use Copilot Chat:**

    - Open the Copilot Chat panel.
    - Enter the following prompt (adjust based on your exact column names if needed):

      ```
      Write a Python function called `check_prediction_accuracy` that takes a single row of a pandas DataFrame as input. The row contains columns 'Simplified Prediction', 'February Average Temperature (Pennsylvania)', and 'March Average Temperature (Pennsylvania)'.

      The function should return:
      - True if the prediction matches the outcome based on the following rules:
          - If 'Simplified Prediction' is 'Long Winter' AND ('March Average Temperature (Pennsylvania)' < 'February Average Temperature (Pennsylvania)' - 1.0)
          - If 'Simplified Prediction' is 'Early Spring' AND ('March Average Temperature (Pennsylvania)' >= 'February Average Temperature (Pennsylvania)' - 1.0)
      - False if the prediction does not match the outcome according to these rules.
      - None (or np.nan) if 'Simplified Prediction' is 'Unknown' or if either required temperature value is missing (NaN).

      Make sure to handle potential NaN values in the temperature columns before comparison. Import numpy as np if needed.
      ```

    - Copy the generated function code into your `phil_analysis.py` script. Ensure `import numpy as np` is present if needed.

3.  **Apply the Function:** Ask Copilot (either via comment completion or Chat) how to apply this function to create a new 'Accuracy' column:
    `# Apply the accuracy check function to each row to create an 'Accuracy' column`
    _(Likely suggestion: `df['Accuracy'] = df.apply(check_prediction_accuracy, axis=1)`)_

4.  **Analyze Results:** Ask Copilot to show the results:
    `# Show the distribution of Accuracy (True, False, NaN)`
    _(Likely suggestion: `print(df['Accuracy'].value_counts(dropna=False))`)_

5.  **(Optional) External Data:** Ask Copilot Chat:
    `Show me Python code using requests and pandas to fetch data from 'https://groundhog-day.com/api/v1/groundhogs' and display the names and predictions count for each groundhog.`

---

### Exercise 4: Refactoring, Optimization, and Synthetic Data

**Goal:** Use Copilot to refactor the accuracy calculation for potential performance improvement and generate synthetic data.

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
    - Add the generated code to your script (or a separate one). Print the head of `synthetic_df` to verify.

---

### Exercise 5: Documenting the Analysis

**Goal:** Use Copilot to generate docstrings for functions and create a README file explaining the script.

**Tasks:**

1.  **Generate Docstrings:**
    - If you haven't already, ensure the accuracy logic (either the `check_prediction_accuracy` function or the vectorized code block) is well-defined. If using the function, place your cursor inside it.
    - Use your IDE's Copilot command to "Generate Docs" (e.g., right-click menu or keyboard shortcut).
    - If you used vectorized code, select the relevant block of code. Ask Copilot Chat: "Generate a docstring explaining this block of pandas code which calculates prediction accuracy." Paste the generated docstring as a multi-line comment above the block.
2.  **Add Inline Comments:**
    - Select a section of your code, perhaps the data cleaning steps from Exercise 2.
    - Ask Copilot Chat or use inline edit: "Add inline comments to explain what each step of this data cleaning code does."
3.  **Create README:**

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

    - Copy the generated Markdown content into a new `README.md` file in your project folder.

---

### Exercise 6: Testing the Logic

**Goal:** Use Copilot to generate unit tests for the data cleaning and accuracy logic using `pytest`.

**Tasks:**

1.  Create a new file named `test_phil_analysis.py`.
2.  Import necessary libraries at the top:
    ```python
    import pandas as pd
    import numpy as np
    import pytest
    # Import functions or reference the main script if needed, e.g.:
    # from phil_analysis import check_prediction_accuracy
    # Note: For simplicity here, we might redefine snippets or copy functions under test
    ```
3.  **Test Accuracy Logic:**

    - Ask Copilot Chat (or use the `/tests` command if available):
      ```
      Generate pytest tests for the `check_prediction_accuracy` function (or the equivalent vectorized logic). Create small sample pandas DataFrame rows as test inputs. Include test cases for:
      1. 'Long Winter' prediction, March is significantly colder (Expect True)
      2. 'Long Winter' prediction, March is warmer (Expect False)
      3. 'Early Spring' prediction, March is warmer (Expect True)
      4. 'Early Spring' prediction, March is significantly colder (Expect False)
      5. 'Early Spring' prediction, March is slightly colder but within the 1-degree threshold (Expect True)
      6. 'Unknown' prediction (Expect None/NaN)
      7. Missing February temperature (Expect None/NaN)
      8. Missing March temperature (Expect None/NaN)
      ```
      _(You'll likely need to copy the `check_prediction_accuracy` function itself into the test file or import it properly for the tests to run)_.
    - Copy the generated test functions into `test_phil_analysis.py`.

4.  **Test Simplified Prediction Mapping:**

    - Ask Copilot Chat:
      ```
      Generate pytest tests to verify the logic that creates the 'Simplified Prediction' column. Create a small sample DataFrame with a 'Punxsutawney Phil' column containing 'Full Shadow', 'No Shadow', 'Partial Shadow', and 'No Record'. Assert that the corresponding 'Simplified Prediction' values are 'Long Winter', 'Early Spring', 'Early Spring', and 'Unknown'.
      ```
    - Add these tests to `test_phil_analysis.py`. You might need to encapsulate the mapping logic into a testable function or apply it within the test function itself.

5.  **Run Tests:**
    - Open your terminal in the project directory.
    - Run `pytest`.
    - **Pitfall / Debugging:** If any tests fail, examine the error messages. Use Copilot Chat to help understand _why_ a test might be failing. Paste the failing test and the relevant function/logic from `phil_analysis.py` into Chat and ask: "This pytest test is failing. Can you help me debug the function/logic based on this test failure?" This forces interaction beyond simple generation. Did the original logic handle an edge case correctly? Did the test make a wrong assumption?

---

**Next Steps (Beyond Exercises):**

- Use Copilot to help generate plots (e.g., using Matplotlib or Seaborn) to visualize Phil's accuracy over time or compare temperature distributions for 'Long Winter' vs 'Early Spring' years. Ask Chat: "Using pandas and matplotlib, plot the rolling average accuracy of Phil's predictions over the years."
- Explore more sophisticated accuracy metrics.
- Refine the handling of missing data using different imputation techniques suggested by Copilot.
