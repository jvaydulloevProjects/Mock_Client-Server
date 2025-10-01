# UDP Client-Server System

**UDP Client-Server System** is a simple network communication project in C++ demonstrating UDP-based messaging between a client and a server. The project showcases socket programming, message encoding/decoding, and basic request-response handling.

---

## 📌 Key Features

- **UDP Server (`Net::Server`)**:
  - Listens on a specified IP and port.
  - Receives messages from clients.
  - Handles simple message types (`PING` / `PONG`) using a custom protocol.
  - Sends replies back to the client.
- **UDP Client (`Net::Client`)**:
  - Connects to a server via IP and port.
  - Sends messages to the server.
  - Receives replies from the server.
- **Custom Protocol** (`Protocol.hpp`):
  - Encodes and decodes message types.

---

## 🏗️ Project Structure

├── include/
│ ├── client.hpp
│ ├── server.hpp
│ └── protocol.hpp
├── src/
│ ├── client.cpp
│ └── server.cpp
├── main_client.cpp
└── main_server.cpp

### Main Classes

| Class | Purpose |
|-------|---------|
| `Net::Server` | UDP server that receives messages, processes them, and sends replies |
| `Net::Client` | UDP client that sends messages to the server and receives responses |
| `Protocol` | Defines message types (`PING`, `PONG`) and encoding/decoding methods |

---

## 🚀 Installation and Running

1. ** Clone the repository**
```bash
git clone https://github.com/jvaydulloevProjects/PING-PONG_Client-Server.git
cd PING-PONG_Client-Server
```
2. **Compile the server and client**
```bash
  g++ -std=c++17 src/server.cpp main_server.cpp -o UDPServer
  g++ -std=c++17 src/client.cpp main_client.cpp -o UDPClient
```
3. **Run the server**
```bash
./UDPServer
```
4. **Run the client**
```bash
./UDPClient
```

Server logs:
```
Server listen
Received: PING
Sended: PONG
Received: PONG
Sended: PING

```

Client logs
```
Enter: PING
Sended to server: PING
Received from server: PONG
Enter: PONG
Sended to server: PONG
Received from server: PING
```
