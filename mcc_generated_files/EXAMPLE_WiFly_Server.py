'''
/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
'''

import socket
from string import rstrip

s = socket.socket()
host = socket.gethostname()
port = 1337

s.bind((host,port))
print 'Socket bound'

s.listen(5)

c, addr = s.accept()
print 'Connection from', addr[0], '\n'

c.settimeout(5.0)

try:
    (c.recv(1024))
    c.send("Proceed\n")
    
    print("Remote: " + c.recv(1024))
    
    response = "Who's there?\n"
    c.send(response)
    print("Server: " + response)
    
    whos = rstrip((c.recv(1024)))
    print("Remote: " + whos + "\n")
    
    response = (whos + " who?\n")
    c.send(response)
    print("Server: " + response)
    
    print("Remote: " + c.recv(1024))
    
except socket.timeout:
    print 'Receive timed out'
    
c.close()
print "Connection closed"
s.close()
print "Socket closed"