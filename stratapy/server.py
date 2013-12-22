import wsgiref.simple_server
import webapp2
from xml.dom import minidom
from WSDiscovery import WSDiscovery, QName, Scope


class MyWebapp(webapp2.RequestHandler):
    def get(self):
        self.response.write('Hello')

    def post(self):
        dom = minidom.parseString(self.request.body)
        print dom.toprettyxml()
        self.response.write('blah')

app = webapp2.WSGIApplication(
    [
        ('/.*', MyWebapp),
    ],
    debug = True
)



def main():
    wsd = WSDiscovery()
    wsd.start()

    ty1 = QName('http://schemas.xmlsoap.org/ws/2006/02/devprof', 'Device')
    ty2 = QName('http://schemas.microsoft.com/windows/2006/08/wdp/print', 'PrintDeviceType')

    sco = Scope('http://myscope')

    xaddr = 'http://uri4:8080/abc'

    wsd.publishService(types=[ty1, ty2], scopes=[], xAddrs=[xaddr])

    #raw_input('press [Enter]: ')

    server = wsgiref.simple_server.make_server('192.168.24.21', 8080, app)
    server.serve_forever()

main()
