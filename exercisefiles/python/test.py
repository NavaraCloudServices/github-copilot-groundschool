import pytest
import requests

def test_key_not_passed():
    response = requests.get('http://localhost:3000/get')
    assert response.text == 'key not passed'

    # add test to check get when key is equal to world

    # add test to check validatephoneNumber

    # write test to validate validateSpanishDNI
   
    # write test for returnColorCode red should return code #FF0000

    # write test for daysBetweenDates
