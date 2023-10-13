s = "abcabcbb";
res = "";
wd=len(s);
hashMap = {};

start=0
end=len(s) 

for i in range(len(s), 0):
	# print(s[i]);
	for j in range(start, end):
		hashMap[s[j]]+=1;
		if hashMap[s[j]] > 1 :
			break;
		else:
			res = res+s[j];


"""
		res
a: 2	a
b: 1	ab
c: 1	abc

"""