"""
Test suite for the Punxsutawney Phil data analysis script.

Run with: pytest test_phil_analysis.py
"""

import pandas as pd
import numpy as np
import pytest

# Assuming the main script is named phil_analysis.py and is in the same directory
from phil_analysis import main


def test_main_function():
    """Test that the main function executes without raising any exceptions."""
    main()
