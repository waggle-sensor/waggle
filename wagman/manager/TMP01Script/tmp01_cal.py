#Set these values

th = 55 #upper temperature in C
tl = -30 #lower temperature in C
th = 5 #hysterisis temperature in C

#th = 20 #upper temperature in C
#tl = 0 #lower temperature in C
#th = 5 #hysterisis temperature in C


vr = 2.5

ivref = (0.000005*th)+ (0.000007)

vsh = (th + 273.15) * (0.005)
vsl = (tl + 273.15) * (0.005)

print vr, vsh, vsl

r1 = (vr - vsh)/ivref
r2 = (vsh-vsl)/ivref
r3 = vsl/ivref

print r1, r2, r3
