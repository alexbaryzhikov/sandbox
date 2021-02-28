const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');

  const path = req.url.substring(req.url.lastIndexOf("/"))
  if (path == "/foo") {
    res.end('Foontastic!');
  } else {
    res.end('Hello and goodbye');
  }
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});