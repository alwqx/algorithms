class HashTable:
    def __init__(self):
        self.size = 11
        self.data = [None]*self.size
        self.slots = [None]*self.size #插槽

    def put(self, key, value):
        hashvalue = self.hashfunc(key, self.size)

        if self.slots[hashvalue] is None:
            self.slots[hashvalue] = key
            self.data[hashvalue] = value
        else:
            if self.slots[hashvalue] == key:
                self.data[hashvalue] = value
            else:
                nexthash = rehashfunc(hashvalue, self.size)
                while self.slots[nexthash] is not None and \
                                self.slots[nexthash] != key:
                    nexthash = rehashfunc(nexthash, self.size)

                if self.slots[nexthash] is None:
                    self.slots[nexthash] = key
                    self.data[nexthash] = value
                else:
                    self.data[nexthash] = value

    def get(self, key):
        startvalue = self.hashfunc(key, self.size)

        found = False
        stop = False
        pos = startvalue
        data = None

        while self.slots[pos] is not None and \
                        not found and not stop:
            if self.slots[pos] == key:
                data = self.data[pos]
                found = True
            else:
                pos = self.rehashfunc(pos, self.size)
                if pos == starvalue:
                    stop = True

        return data

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, value):
        self.put(key, value)

    def hashfunc(self, key, size):
        return key%size

    def rehashfunc(self, key, size):
        return (key+1)%size

def test_hashtable():
    ht = HashTable()
    ht[1] = "luke"
    ht[5] = "lwq"
    ht[3] = "wr"
    ht[9] = "zsy"
    ht[10] = "mm"

    assert ht[1] == "luke"
    assert ht[10] != "mmr"
    assert ht[40] is None
