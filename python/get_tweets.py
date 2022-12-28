import requests

# Bearer token for the Twitter API
bearer_token = "AAAAAAAAAAAAAAAAAAAAAJaDkwEAAAAArF%2F0Ia%2Bn0hydQqY6RRkqlZGz8Yw%3D9xJpFxuUhDMEN0GQz9JWKLiTAF8ykYo25bpts0luTPNdOcUQXu"

# Send a request to the Twitter API to fetch the latest tweets of the user with given id
user_id = "44196397"
response = requests.get(
    f"https://api.twitter.com/2/users/{user_id}/tweets",
    headers={
        "Authorization": f"Bearer {bearer_token}"
    }
)

# Extract the tweets from the response
tweets = response.json()

# Print the tweets
print(tweets)
