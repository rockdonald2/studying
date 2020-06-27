try:
    be = open('be.txt', 'r')
    ki = open('ki.txt', 'w')
except OSError:
    print('Allomany megnyitasa sikertelen')
    exit(-1)

tartalom = be.read()

tartalom = tartalom.split()

maganhangzosSzavak = list(filter(lambda szo : 'a' in szo or 'e' in szo or 'o' in szo or 'u' in szo or 'i' in szo, tartalom))

ki.write('\n'.join(maganhangzosSzavak))

be.close()
ki.close()