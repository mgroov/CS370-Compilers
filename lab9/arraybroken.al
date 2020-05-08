int x, y, z;
boolean t, f;


void main(void)
begin
t =true;
f = false;
write "2 + 3";
write 2 + 3;

x = 3 * 2;
write "3 * 2";
write x;

write "4 + 7 * 2 - 8 / 4 (should be 16)";
y = 4 + 7 * 2 - 8 / 4;
write y;

z = 6 / 2;
write "6 / 2";
write z;

x = 5 - 4;
write "5 - 4";
write x;

y = x;
z = 0;


write "Testing NOT";
if not t
then
write "not failed";
else
write "not passed";

if not f
then
write "not passed";
else
write "not failed";


write "Testing AND";
if y and z
then
write "and failed";
else
write "and passed";

if y and y
then
write "and passed";
else
write "and failed";


write "Testing OR";
if y or z
then
write "or passed";
else
write "or failed";

if z or z
then
write "or failed";
else
write "or passed";


write "Testing ==";
if x == y then
write "== passed";
else
write "== failed";

if x == z then
write "== failed";
else
write "== passed";


write "Testing !=";
if x != z then
write "!= passed";
else
write "!= failed";

if x != z then
write "!= failed";
else
write "!= passed";


write "Testing <";
if z < x then
write "!= passed";
else
write "!= failed";

if x < z then
write "!= failed";
else
write "!= passed";

if x < x then
write "!= failed";
else
write "!= passed";


write "Testing >";
if x > z then
write "!= passed";
else
write "!= failed";

if z > x then
write "!= failed";
else
write "!= passed";

if x > x then
write "!= failed";
else
write "!= passed";


write "Testing <=";
if z <= x then
write "!= passed";
else
write "!= failed";

if x <= z then
write "!= failed";
else
write "!= passed";

if x <= x then
write "!= passes";
else
write "!= failed";


write "Testing >=";
if x >= z then
write "!= passed";
else
write "!= failed";

if z >= x then
write "!= failed";
else
write "!= passed";

if x >= x then
write "!= passed";
else
write "!= failed";

write "Testing while (expecting 6 writes)";
while x
do begin
write "Look ma, I'ma loop!";
x = x - 1;
end
write "Loop landed!";


end
