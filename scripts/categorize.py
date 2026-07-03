import requests

url = "https://leetcode.com/graphql"

query = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    difficulty
  }
}
"""

variables = {
    "titleSlug": "two-sum"
}

response = requests.post(
    url,
    json={
        "query": query,
        "variables": variables
    }
)

print(response.json())