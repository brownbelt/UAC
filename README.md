HOW TO USE:

Drop the fake.cab into your c:\users\%username%\downloads folder (or change it in the source code ;) 

Run lpe.exe  .... this will drop the contents of our cab file into system32!


HOW THIS WORKS:

We run wusa with a cab file as argument. This will try to extract the contents into a random folder in "c:\", we watch for the creation of this folder and turn it into a junction to system32.

HOW TO EXPLOIT:

I found this bug a year ago, back then I had a dll hijacking vuln to get system. However, this has been patched.
Either find a new dll hijacking vuln. Or find a way to delete dlls in system32 and then replace them with a malicious one.
This last idea should be trivial enough, there are plenty of ways to achieve this, especially using junctions on an admin account.
And atleast leaving out this part will prevent scriptkiddies from using this ;).

FINAL THOUGHTS:

UAC is really easy to bypass. I understand that it is not considered a security boundary, the attack surface is too big.. and perhaps the solution is not making UAC a security boundary.. but advising people to use non-admin accounts, enforcing least privilege is also the user's task! ;).
