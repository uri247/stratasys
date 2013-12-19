from WSDiscovery import WSDiscovery, QName, Scope



def main():
    wsd = WSDiscovery()
    wsd.start()

    ty1 = QName('http://schemas.xmlsoap.org/ws/2006/02/devprof', 'Device')
    ty2 = QName('http://schemas.microsoft.com/windows/2006/08/wdp/print', 'PrintDeviceType')

    sco = Scope('http://myscope')

    xaddr = 'dt1.london.home:80/abc'

    wsd.publishService(types=[ty1, ty2], scopes=[sco], xAddrs=[xaddr])

    raw_input('press [Enter]: ')


main()
