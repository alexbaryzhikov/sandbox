#!/bin/bash

curl http://localhost:5000
curl -X GET http://localhost:5000
curl -d "user=user1&pass=abcd" -X POST http://localhost:5000/login
curl -d '{ "user": "user1", "pass": "abcd" }' -H 'Content-Type: application/json' -X POST http://localhost:5000/login
curl -X POST -F "fileupload=@test.sh" http://localhost:5000/upload
