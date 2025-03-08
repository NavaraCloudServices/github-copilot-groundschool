import pytest
import requests

def test_key_not_passed():
    response = requests.get('http://localhost:3000/hello')
    assert response.text == 'name not passed'