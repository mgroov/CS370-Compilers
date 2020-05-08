int x, y, z;
int p[5];
boolean t;
boolean f;

void main(void)
begin
write "2 + 3";
write 2 + 3;
t=true;
f=false;

x = 3 * 2;
write "3 * 2";
write x;

write "4 + 7 * 2 - 8 / 4 (should be 16)";
p[3] = 4 + 7 * 2 - 8 / 4;
write p[3];

y = 6 / 2;
write "6 / 2";
write y;

p[0] = 5 - 4;
write "5 - 4";
write p[0];

p[1] = p[0];
p[2] = 0;


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
if p[0] and p[2]
then
write "and failed";
else
write "and passed";

if p[0] and p[1]
then
write "and passed";
else
write "and failed";


write "Testing OR";
if p[0] or p[2]
then
write "or passed";
else
write "or failed";

if p[2] or p[2]
then
write "or failed";
else
write "or passed";


write "Testing ==";
if p[0] == p[1] then
write "== passed";
else
write "== failed";

if p[0] == p[2] then
write "== failed";
else
write "== passed";


write "Testing !=";
if p[0] != p[2] then
write "!= passed";
else
write "!= failed";

if p[0] != p[1] then
write "!= failed";
else
write "!= passed";


write "Testing <";
if p[2] < p[0] then
write "!= passed";
else
write "!= failed";

if p[0] < p[2] then
write "!= failed";
else
write "!= passed";

if p[0] < p[0] then
write "!= failed";
else
write "!= passed";


write "Testing >";
if p[0] > p[2] then
write "!= passed";
else
write "!= failed";

if p[2] > p[0] then
write "!= failed";
else
write "!= passed";

if p[0] > p[0] then
write "!= failed";
else
write "!= passed";


write "Testing <=";
if p[2] <= p[0] then
write "!= passed";
else
write "!= failed";

if p[0] <= p[2] then
write "!= failed";
else
write "!= passed";

if p[0] <= p[0] then
write "!= passes";
else
write "!= failed";


write "Testing >=";
if p[0] >= p[2] then
write "!= passed";
else
write "!= failed";

if p[2] >= p[0] then
write "!= failed";
else
write "!= passed";

if p[0] >= p[0] then
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
