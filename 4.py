grade = input("Enter your grade:\n")
if(grade == 'A'):
	basic = 10000
	Allow = 1700
	PF = 0.11*basic
	HRA = 0.2*basic
	DA = 0.5*basic

elif(grade == 'B'):
	basic = 4567
	Allow = 1500
	PF = 0.11*basic
	HRA = 0.2*basic
	DA = 0.5*basic
	
elif(grade == 'C'):
	basic = 2500
	Allow = 1300
	PF = 0.11*basic
	HRA = 0.2*basic
	DA = 0.5*basic
	
else:
	print("Invalid grade")
	
salary = basic + HRA + DA + Allow -PF

print("Your Gross Salary is: ", salary)
