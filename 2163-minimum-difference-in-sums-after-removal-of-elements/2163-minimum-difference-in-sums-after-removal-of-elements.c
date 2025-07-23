void HeapifyDownLeft(int** ppnStart, int** ppnEnd, int** ppnCurr)
{
    int** ppnChild = 1 + ppnStart + ((ppnCurr-ppnStart)<<1);
    if(ppnChild <= ppnEnd)
    {
        if(ppnChild < ppnEnd && **ppnChild < **(1+ppnChild)) ppnChild++;

        if(**ppnCurr < **ppnChild)
        {
            int* pnTmp = *ppnCurr;
            *ppnCurr = *ppnChild;
            *ppnChild = pnTmp;

            HeapifyDownLeft(ppnStart, ppnEnd, ppnChild);
        }
    }
}

void HeapifyUpLeft(int** ppnStart, int** ppnCurr)
{
    if(ppnStart < ppnCurr)
    {
        int** ppnParent = ppnStart + ((-1+ppnCurr-ppnStart)>>1);
        if(**ppnParent < **ppnCurr)
        {
            int* pnTmp = *ppnParent;
            *ppnParent = *ppnCurr;
            *ppnCurr = pnTmp;

            HeapifyUpLeft(ppnStart, ppnParent);
        }
    }
}

void HeapifyDownRight(int** ppnStart, int** ppnEnd, int** ppnCurr)
{
    int** ppnChild = 1 + ppnStart + ((ppnCurr-ppnStart)<<1);
    if(ppnChild <= ppnEnd)
    {
        if(ppnChild < ppnEnd && **ppnChild > **(1+ppnChild)) ppnChild++;

        if(**ppnChild < **ppnCurr)
        {
            int* pnTmp = *ppnChild;
            *ppnChild = *ppnCurr;
            *ppnCurr = pnTmp;

            HeapifyDownRight(ppnStart, ppnEnd, ppnChild);
        }
    }
}

void HeapifyUpRight(int** ppnStart, int** ppnCurr)
{
    if(ppnStart < ppnCurr)
    {
        int** ppnParent = ppnStart + ((-1+ppnCurr-ppnStart)>>1);
        if(**ppnCurr < **ppnParent)
        {
            int* pnTmp = *ppnCurr;
            *ppnCurr = *ppnParent;
            *ppnParent = pnTmp;

            HeapifyUpRight(ppnStart, ppnParent);
        }
    }
}

long long minimumDifference(int* nums, int numsSize) {
    // calculate first numsSize/3
    numsSize /= 3;
    int nNumsSize = numsSize;
    int* apnHeapify[numsSize];
    int** ppnHeapify = apnHeapify;
    long long llSum = 0;
    while(nNumsSize--)
    {
        llSum += *nums;

        *ppnHeapify = nums++;
        HeapifyUpLeft(apnHeapify, ppnHeapify++);
    }

    long long allSum[1+numsSize];
    long long* pllSum = allSum;
    *pllSum = llSum;

    // calculate middle numsSize/3
    ppnHeapify--;
    nNumsSize = numsSize;
    while(nNumsSize--)
    {
        if(*nums < **apnHeapify)
        {
            llSum += *nums - **apnHeapify;

            *apnHeapify = nums;
            HeapifyDownLeft(apnHeapify, ppnHeapify, apnHeapify);
        }

        *(++pllSum) = llSum;
        nums++;
    }

    // calculate last numsSize/3
    nNumsSize = numsSize;
    ppnHeapify = apnHeapify;
    llSum = 0;
    while(nNumsSize--)
    {
        llSum += *nums;

        *ppnHeapify = nums++;
        HeapifyUpRight(apnHeapify, ppnHeapify++);
    }

    // re-calculate middle numsSize/3
    nums -= numsSize;
    ppnHeapify--;
    long long llRet = *pllSum - llSum;
    while(numsSize--)
    {
        pllSum--;
        if(*(--nums) > **apnHeapify)
        {
            llSum += *nums - **apnHeapify;
            long long llTmp = *pllSum - llSum;
            if(llTmp < llRet) llRet = llTmp;

            *apnHeapify = nums;
            HeapifyDownRight(apnHeapify, ppnHeapify, apnHeapify);
        }
    }

    return llRet;
}