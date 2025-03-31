import pytest
import requests

def test_name_not_passed():
    response = requests.get('http://localhost:3000/hello')
    assert response.text == 'name not passed'