function createRandomArray(len,max)
	local ret = {}
	for i=1,len do
		local v = math.random(max)
		table.insert(ret,v)
	end
	local function cout()
		for i,v in ipairs(ret) do
			print(i,v)
		end
	end
	ret.cout = cout
	-- ret.cout()
	return ret
end

function insertionSort(array)
	for j = 2,#array do
		local key = array[j]
		local i = j -1
		while i > 1 and array[i] > key do
			array[i+1] = array[i]
			i = i -1
		end
		array[i+1] = key
	end
	array.cout()
end


function selectSort( array )
	for i = 1,#array -1  do
		local minIndex = i
		for j = i+1,#array do
			if array[j] < array[minIndex] then
				minIndex = j
			end
			j = j + 1
			print("i:"..i.." j:"..j)
		end
		local temp = array[i]
		array[i] = array[minIndex]
		array[minIndex] = temp
	end
	array.cout()
	-- body
end


function quickSort(array,p,r)
	local function partition(array,p,r)
		local x = array[r]
		local i = p-1
		for j=p,r-1 do
			if array[j] <= x then
				i = i +1
				local temp = array[i]
				array[i] = array[j]
				array[j] = temp
			end
		end
		local temp = array[i+1]
		array[i+1] = array[r]
		array[r] = temp
		return i+1
	end
	if p < r then
		q = partition(array,p,r)
		quickSort(array,p,q-1)
		quickSort(array,q+1,r)
	end
end


function findRight()
	local a = {0,1,2,3,4,5}
	local b = {0,1,2,3,4,5}
	local function appearCount(num)
		local ret = 0
		for i=1,#b do
			if b[i] == num then
				ret = ret + 1
			end
		end
		return ret
	end
	while true do
		local rightCount = 0
		for k,v in pairs(a) do
			local count = appearCount(v)
			if count == b[k] then
				rightCount = rightCount + 1
			else
				b[k] = count
			end
		end
		if rightCount == 10 then
			break
		end
	end
	for k,v in pairs(b) do
		print(k,v)
	end

end

function findInterSection(A,B)
	local ret = {}
	local aa = {}
	for k,v in pairs(A) do
		aa[v] = 1
	end
	for k,v in pairs(B) do
		if aa[v] == 1 then
			aa[v] = 2
			table.insert(ret,v)
		end
	end
	for i,v in ipairs(ret) do
		print(i,v)
	end
end

-- findRight()
local a = createRandomArray(5,10)
a.cout()
print("---")
local b = createRandomArray(5,10)
b.cout()
print("---")
findInterSection(a,b)
-- array = createRandomArray(100000,100)
-- array.cout()
-- quickSort(array,1,#array)
-- array.cout()




