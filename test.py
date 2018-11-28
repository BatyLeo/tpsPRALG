class a:
    aa = 0

    def z(self):
        return self.aa

az = a()
az.aa += 1
print(az.z())
