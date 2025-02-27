#include "testcase.h"
#include "MyLinkedList.h"
#include "MyHashMap.h"

FUNCNAME g_tFuncName[] = {
    {1,     TestCase_1   },
    {3,     TestCase_3   },
    {5,     TestCase_5   },
    {7,     TestCase_7   },
    {13,    TestCase_13  },
    {15,    TestCase_15  },
    {17,    TestCase_17  },
    {19,    TestCase_19  },
    {20,    TestCase_20  },
    {24,    TestCase_24  },
    {25,    TestCase_25  },
    {26,    TestCase_26  },
    {27,    TestCase_27  },
    {28,    TestCase_28  },
    {30,    TestCase_30  },
    {34,    TestCase_34  },
    {35,    TestCase_35  },
    {39,    TestCase_39  },
    {40,    TestCase_40  },
    {42,    TestCase_42  },
    {43,    TestCase_43  },
    {49,    TestCase_49  },
    {53,    TestCase_53  },
    {55,    TestCase_55  },
    {56,    TestCase_56  },
    {59,    TestCase_59  },
    {62,    TestCase_62  },
    {67,    TestCase_67  },
    {68,    TestCase_68  },
    {69,    TestCase_69  },
    {75,    TestCase_75  },
    {76,    TestCase_76  },
    {77,    TestCase_77  },
    {78,    TestCase_78  },
    {88,    TestCase_88  },
    {92,    TestCase_92  },
    {102,   TestCase_102 },
    {103,   TestCase_103 },
    {108,   TestCase_108 },
    {113,   TestCase_113 },
    {118,   TestCase_118 },
    {120,   TestCase_120 },
    {122,   TestCase_122 },
    {125,   TestCase_125 },
    {127,   TestCase_127 },
    {128,   TestCase_128 },
    {130,   TestCase_130 },
    {136,   TestCase_136 },
    {142,   TestCase_142 },
    {143,   TestCase_143 },
    {150,   TestCase_150 },
    {151,   TestCase_151 },
    {153,   TestCase_153 },
    {160,   TestCase_160 },
    {167,   TestCase_167 },
    {187,   TestCase_187 },
    {189,   TestCase_189 },
    {202,   TestCase_202 },
    {203,   TestCase_203 },
    {205,   TestCase_205 },
    {206,   TestCase_206 },
    {209,   TestCase_209 },
    {210,   TestCase_210 },
    {212,   TestCase_212 },
    {213,   TestCase_213 },
    {216,   TestCase_216 },
    {217,   TestCase_217 },
    {221,   TestCase_221 },
    {224,   TestCase_224 },
    {227,   TestCase_227 },
    {228,   TestCase_228 },
    {229,   TestCase_229 },
    {239,   TestCase_239 },
    {240,   TestCase_240 },
    {242,   TestCase_242 },
    {268,   TestCase_268 },
    {274,   TestCase_274 },
    {283,   TestCase_283 },
    {287,   TestCase_287 },
    {290,   TestCase_290 },
    {297,   TestCase_297 },
    {300,   TestCase_300 },
    {316,   TestCase_316 },
    {322,   TestCase_322 },
    {332,   TestCase_332 },
    {334,   TestCase_334 },
    {342,   TestCase_342 },
    {344,   TestCase_344 },
    {349,   TestCase_349 },
    {350,   TestCase_350 },
    {367,   TestCase_367 },
    {383,   TestCase_383 },
    {387,   TestCase_387 },
    {389,   TestCase_389 },
    {392,   TestCase_392 },
    {394,   TestCase_394 },
    {415,   TestCase_415 },
    {417,   TestCase_417 },
    {435,   TestCase_435 },
    {438,   TestCase_438 },
    {443,   TestCase_443 },
    {452,   TestCase_452 },
    {496,   TestCase_496 },
    {503,   TestCase_503 },
    {509,   TestCase_509 },
    {523,   TestCase_523 },
    {541,   TestCase_541 },
    {542,   TestCase_542 },
    {556,   TestCase_556 },
    {557,   TestCase_557 },
    {566,   TestCase_566 },
    {567,   TestCase_567 },
    {621,   TestCase_621 },
    {704,   TestCase_704 },
    {706,   TestCase_706 },
    {707,   TestCase_707 },
    {713,   TestCase_713 },
    {724,   TestCase_724 },
    {726,   TestCase_726 },
    {735,   TestCase_735 },
    {739,   TestCase_739 },
    {746,   TestCase_746 },
    {766,   TestCase_766 },
    {792,   TestCase_792 },
    {797,   TestCase_797 },
    {784,   TestCase_784 },
    {844,   TestCase_844 },
    {904,   TestCase_904 },
    {905,   TestCase_905 },
    {909,   TestCase_909 },
    {946,   TestCase_946 },
    {947,   TestCase_947 },
    {977,   TestCase_977 },
    {1004,  TestCase_1004},
    {1035,  TestCase_1035},
    {1047,  TestCase_1047},
    {1048,  TestCase_1048},
    {1071,  TestCase_1071},
    {1091,  TestCase_1091},
    {1143,  TestCase_1143},
    {1192,  TestCase_1192},
    {1207,  TestCase_1207},
    {1220,  TestCase_1220},
    {1239,  TestCase_1239},
    {1337,  TestCase_1337},
    {1361,  TestCase_1361},
    {1422,  TestCase_1422},
    {1480,  TestCase_1480},
    {1535,  TestCase_1535},
    {1544,  TestCase_1544},
    {1637,  TestCase_1637},
    {1647,  TestCase_1647},
    {1657,  TestCase_1657},
    {1662,  TestCase_1662},
    {1823,  TestCase_1823},
    {1930,  TestCase_1930},
    {2001,  TestCase_2001},
    {2009,  TestCase_2009},
    {2125,  TestCase_2125 },
    {2215,  TestCase_2215},
    {2251,  TestCase_2251},
    {2483,  TestCase_2483},
    {2742,  TestCase_2742},
    {7001,  TestCase_7001},
    {7002,  TestCase_7002},
    {7003,  TestCase_7003},
    {7004,  TestCase_7004},
    {7005,  TestCase_7005},
    {7006,  TestCase_7006},
    {8005,  TestCase_8005},
    {8058,  TestCase_8058},
    {9998,  TestCase_9998},
    {9999,  TestCase_9999},
};

void TestCase_7006()
{
    int keys1[4] = { 2,1,3,4 };
    createBST(4, keys1); // 0 1 2 4
    int keys2[3] = { 2,1,3 };
    createBST(3, keys2);  // 0 1 2
    int keys3[3] = { 1,2,3 };
    createBST(3, keys3);  // 0 1 3
}

void TestCase_7005()
{
    int count = 0;
    int* result = getOneBits(161, &count);
}

void TestCase_7004()
{
    int heights[5] = { 3,1,5,4,8};
    int rates[5] = { 2,1,2,1,2};
    printf("%d\r\n", maxPlanes(5, heights, 5, rates));
}

void TestCase_7003()
{
    int values[7] = { 3,1,5,6,7,8,3 };
    struct node* root = createList(7, values);
    delete_item(&root, 3);
    while (root)
    {
        printf("%d ", root->value);
        root = root->next;
    }
    printf("\r\n");
}
void TestCase_7002()
{
    vector<int> input, output;
    input = { 52, 234, 80, 700, 1234 };
    output = mysort(input, (int)input.size());
}
void TestCase_7001()
{
    string input = "Hello Word!";
    string output = Reserve(input);
    cout << input << ";" << output << endl;
    input = "abcdef";
    output = Reserve(input);
    cout << input << ";" << output << endl;
}
void TestCase_127()
{
    vector<string> wordList;
    string begin, end;
    int ans;

    wordList = { "hot","dot","dog","lot","log","cog" };
    begin = "hit", end = "cog";
    ans = ladderLength(begin, end, wordList);

    wordList = { "a","b","c"};
    begin = "a", end = "c";
    ans = ladderLength(begin, end, wordList);
}

void TestCase_2125()
{
    vector<string> bank;
    int output;

    bank = { "011001","000000","010100","001000" };
    output = numberOfBeams(bank);

    bank = { "000","111","000" };
    output = numberOfBeams(bank);
}

void TestCase_1422()
{
    string s= "00111";
    maxScore(s);
}

void TestCase_210()
{
    vector<vector<int>> points;
    points = { {1,0} ,{2,0},{3,1},{3,2} };
    findOrder(4, points);
}
void TestCase_1637()
{
    vector<vector<int>> points;

    points = { {8, 7} ,{9, 9},{7, 4},{9, 7} };
    maxWidthOfVerticalArea(points);
}

void TestCase_30()
{
    string s;
    vector<string> words;
    
    s = "wordgoodgoodgoodbestword";
    words = { "word","good","best","good" };
    findSubstring(s, words);

    s = "barfoofoobarthefoobarman";
    words = { "bar","foo","the" };
    findSubstring(s, words);
}

void TestCase_909()
{
    vector<vector<int>> board;
    int output;
    board = {   {-1,-1,-1,-1,-1,-1} ,
                {-1,-1,-1,-1,-1,-1},
                {-1,-1,-1,-1,-1,-1},
                {-1,35,-1,-1,13,-1},
                {-1,-1,-1,-1,-1,-1},
                {-1,15,-1,-1,-1,-1} };
    output = snakesAndLadders(board);

    board = {    {-1, -1},
                {-1, 3} };
    output = snakesAndLadders(board);
}

void TestCase_68()
{
    vector<string> words;
    int maxWidth;
    vector<string> ans;

    words = { "This", "is", "an", "example", "of", "text", "justification." };
    maxWidth = 16;
    ans = fullJustify(words, maxWidth);

    words = { "What","must","be","acknowledgment","shall","be" };
    maxWidth = 16;
    ans = fullJustify(words, maxWidth);

    words = { "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do" };
    maxWidth = 20;
    ans = fullJustify(words, maxWidth);
}

void TestCase_9998()
{
    string result;
    result = TranserHexAdecimal(107);
    printf("%s\r\n", result.c_str());
    result = TranserHexAdecimal(2147483647);
    printf("%s\r\n", result.c_str());
}

void TestCase_128()
{
    vector<int> nums = { 100,4,200,1,3,2 };
    longestConsecutive(nums);
}

void TestCase_224()
{
    string s = " 2-1 + 2 ";
    calculate(&*s.begin());
}

void TestCase_221()
{
    vector<vector<char>> matrix = {
        {'0','1','1','0','0','1','0','1','0','1'},
        {'0','0','1','0','1','0','1','0','1','0'},
        {'1','0','0','0','0','1','0','1','1','0'},
        {'0','1','1','1','1','1','1','0','1','0'},
        {'0','0','1','1','1','1','1','1','1','0'},
        {'1','1','0','1','0','1','1','1','1','0'},
        {'0','0','0','1','1','0','0','0','1','0'},
        {'1','1','0','1','1','0','0','1','1','1'},
        {'0','1','0','1','1','0','1','0','1','1'},
    };
    char** p;
    int row = 9, col = 10;
    p = (char**)malloc(row * sizeof(char*));

    for (int i = 0; i < row; i++) {
        p[i] = (char*)malloc(col * sizeof(char));
        memcpy(p[i], matrix[i].data(), col);

    }
    maximalSquare(p, row, &col);

    for (int i = 0; i < row; i++)
        free(p[i]);
    free(p);
}

void TestCase_1930()
{
    string s = "bbcbaba";
    countPalindromicSubsequence(&*s.begin());
}

void TestCase_1192()
{
    vector<int> dist, speed;
    dist = { 1,3,4 };
    speed = { 1,1,1 };
    eliminateMaximum(dist.data(), 3, speed.data(), 3);

    dist = { 1,4,3,1 };
    speed = { 1,1,1,1 };
    eliminateMaximum(dist.data(), 4, speed.data(), 4);
}

void TestCase_1535()
{
    vector<int> arr = { 2,1,3,5,4,6,7 };
    int out, exp;

    exp = 5;
    out = getWinner(arr, 2);
    COMPVALUE(exp, out);

    arr = { 3,2,1 };
    exp = 3;
    out = getWinner(arr, 10);
    COMPVALUE(exp, out);

    arr = { 1,11,22,33,44,55,66,77,88,99 };
    exp = 99;
    out = getWinner(arr, 1000000000);
    COMPVALUE(exp, out);

}

void TestCase_13()
{
    string s = "DCXXI";
    romanToInt(&*s.begin());
}

void TestCase_5()
{
    string s;
    string out;

    s = "cbbd";
    out = longestPalindromeDP(s);

    s = "babad";
    out = longestPalindromeDP(s);
}
void TestCase_122()
{
    vector<int> prices;
    prices = { 5,2,3,2,6,6,2,9,1,0,7,4,5,0 };

    maxProfitII(prices.data(), (int)prices.size());
}

void TestCase_1220()
{
    for(int i=1;i<=5;i++)
        countVowelPermutation(i);
}

void TestCase_67()
{
    string a, b;

    a = "1";
    b = "111";
    addBinary(&*a.begin(), &*b.begin());

    a = "1010";
    b = "1011";
    addBinary(&*a.begin(), &*b.begin());
}

void TestCase_274()
{
    vector<int> nums;

    nums = { 4,4,0,0 };
    hIndex(nums.data(), (int)nums.size());

    nums = { 3,0,6,1,5 };
    hIndex(nums.data(), (int)nums.size());
}

void TestCase_228()
{
    vector<int> nums;
    int count;
    nums.clear();
    summaryRanges(nums.data(), (int)nums.size(), &count);

    nums = { 0,1,2,4,5,7 };
    summaryRanges(nums.data(), (int)nums.size(), &count);

}

void TestCase_125()
{
    string s = "0P";

    isPalindrome(&*s.begin());
}
void TestCase_342()
{
    int n;

    n = 8;
    isPowerOfFour(n);
}

void TestCase_42()
{
    vector<int> height;

    height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    trap(height.data(), (int)height.size());
}

void TestCase_556()
{
    int n, expect, out;

    n = 2147483486;
    expect = -1;
    out = nextGreaterElement(n);
    COMPVALUE(expect, out);

    n = 2302431;
    expect = 2303124;
    out = nextGreaterElement(n);
    COMPVALUE(expect, out);

    n = 1234;
    expect = 1243;
    out = nextGreaterElement(n);
    COMPVALUE(expect, out);

    n = 556;
    expect = 565;
    out = nextGreaterElement(n);
    COMPVALUE(expect, out);
}

void TestCase_503()
{
    vector<int> nums;
    int count;

    nums = { 1,2,3,4,3 };
    nextGreaterElements(nums.data(), (int)nums.size(), &count);
}

void TestCase_496()
{
    vector<int> nums1, nums2;
    int count;

    nums1 = { 4,1,2 };
    nums2 = { 1,3,4,2 };
    nextGreaterElement(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &count);
}

void TestCase_739()
{
    vector<int> temperatures;
    int count;

    temperatures = { 73,74,75,71,69,72,76,73 };
    dailyTemperatures(temperatures.data(), (int)temperatures.size(), &count);
}

void TestCase_1361()
{
    vector<int> left, right;
    int n;
    bool res;

    left = { 3,-1,1,-1 };
    right = { -1,-1,0,-1 };
    n = (int)left.size();
    res = validateBinaryTreeNodes(n, left.data(), n, right.data(), n);

    left = { 1,-1,-1,4,-1,-1 };
    right = { 2,-1,-1,5,-1,-1 };
    n = (int)left.size();
    res = validateBinaryTreeNodes(n, left.data(), n, right.data(), n);
}

void TestCase_2742()
{
    vector<int> costs, times;
    costs = { 1,2,3,2 };
    times = { 1,2,3,2 };
    paintWalls(costs.data(), (int)costs.size(), times.data(), (int)times.size());
}

void TestCase_726()
{
    string formula;
    string res;
    string output;

    formula = "Kzzz4(ON(SxxOppp3)25)2";
    res = countOfAtoms(formula);

    formula = "K4(ON(SO3)2)2";
    res = countOfAtoms(formula);
    output = "K4N2O14S4";
}

void TestCase_394()
{
    string s; 
    string res;

    s = "100[leetcode]";
    res = decodeString(s);

    s = "3[a]2[bc]";
    res = decodeString(s);

    s = "3[a2[c]]";
    res = decodeString(s);

    s = "2[abc]3[cd]ef";
    res = decodeString(s);
}

void TestCase_452()
{
    vector<vector<int>> points = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};

    int** p;
    int size, col;

    points = { {-2147483646,-2147483645} ,{2147483646,2147483647} };
    size = (int)points.size(), col = 2;
    p = matrix2addr(points);

    findMinArrowShots(p, size, &col);
}

void TestCase_792()
{
    string s = "abcde";
    vector<string> vstr = {"a", "bb", "acd", "ace"};
    char** strs;

    strs = (char**)malloc(sizeof(char*) * vstr.size());
    for (int i = 0; i < (int)vstr.size(); i++) {
        int len = (int)vstr[i].size();
        strs[i] = (char*)malloc(len + 1);
        memcpy(strs[i], vstr[i].c_str(), len);
        strs[i][len] = '\0';
    }

    numMatchingSubseq(&*s.begin(), strs, (int)vstr.size());
}

void TestCase_2251()
{
    vector<vector<int>> flowers = { {1,6} ,{3,7},{9,12},{4,13} };
    vector<int> peoples = { 2,3,7,11 };
    int** p;
    int size, col;

    size = (int)flowers.size(), col = 2;
    p = matrix2addr(flowers);

    fullBloomFlowers(p, size, &col, peoples.data(), (int)peoples.size(), &size);
}

void TestCase_2009()
{
    vector<int> nums = { 1,2,3,5,6 };
    minOperations(nums);
}

void TestCase_1207()
{
    vector<int> arr = { 1, 2, 2, 1, 1, 3 };
    //uniqueOccurrences(arr.data(), (int)arr.size());

    //arr = { 1,2 };
    //uniqueOccurrences(arr.data(), (int)arr.size());

    arr = { -3,0,1,-3,1,1,1,-3,10,0 };
    uniqueOccurrences(arr.data(), (int)arr.size());
}

void TestCase_229()
{
    int count = 0;
    vector<int> nums = { 6,5,5 };
    majorityElement(nums.data(), (int)nums.size(), &count);
}

void TestCase_443()
{
    string chars = "abbbbbbbbbbbb";
    compress(&*chars.begin(), (int)chars.size());
}

void TestCase_2001()
{
    int retSize = 0;
    vector<vector<int>> rectangles = { {4,8} ,{3,6},{10,20},{15,30} };
    interchangeableRectangles(rectangles);
}

void TestCase_905()
{
    int retSize = 0;
    vector<int> nums = { 0,2,1,4 };
    sortArrayByParity(nums.data(), (int)nums.size(), &retSize);
}

void TestCase_316()
{
    string s = "cbacdcbc";
    removeDuplicateLetters(&*s.begin());
}

void TestCase_389()
{
    string s = "ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor";
    string t = "qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj";

    char res = findTheDifference(&*s.begin(), &*t.begin());
}

void TestCase_1048()
{
    vector<string> words = { "a","b","ba","bca","bda","bdca" };
    //longestStrChain(words);

    words = { "xbc","pcxbcf","xb","cxbc","pcxbc" };
    longestStrChain(words);

}

void TestCase_334()
{
    vector<int> nums;

    nums = { 20,100,10,12,5,13 };
    increasingTriplet(nums.data(), (int)nums.size());
}

void TestCase_287()
{
    vector<int> nums;

    nums = { 1,3,4,2,2 };
    findDuplicate(nums);
}

void TestCase_1337()
{
    vector<vector<int>> mat = { { 1,1,0,0,0} ,
        { 1,1,1,1,0},
        {1,0,0,0,0 },
        {1, 1, 0, 0, 0},
        {1,1,1,1,1} };

    kWeakestRows(mat, 3);
}

void TestCase_332()
{
    //vector<vector<string>> tickets = { {"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"} };
    vector<vector<string>> tickets = { {"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    findItinerary(tickets);
}

void TestCase_1647()
{
    string s;

    s = "bbcebab";
    minDeletions(s);
}
void TestCase_92()
{
    vector<int> nums1;

    ListNode* output = NULL;
    struct ListNode* headA;

    nums1 = { 1,2,3,4,5 };
    headA = CreateListNode(nums1);
    headA = reverseBetween(headA, 2, 4);
}

void TestCase_2483()
{
    string customers;
    int expect, out;

    customers = "NYNNNYYN";
    expect = 0;
    out = bestClosingTime(customers);
    COMPVALUE(expect, out);

    customers = "YYNY";
    expect = 2;
    out = bestClosingTime(customers);
    COMPVALUE(expect, out);
    
    customers = "NNNYNN";
    expect = 0;
    out = bestClosingTime(customers);
    COMPVALUE(expect, out);

    customers = "NNNN";
    expect = 0;
    out = bestClosingTime(customers);
    COMPVALUE(expect, out);

    customers = "YYYY";
    expect = 4;
    out = bestClosingTime(customers);
    COMPVALUE(expect, out);
}
void TestCase_268()
{
    vector<int> nums1;
    int expect, out;

    nums1 = { 9,6,4,2,3,5,7,0,1 };
    expect = 8;
    out = missingNumber(nums1.data(), (int)nums1.size());
    COMPVALUE(expect, out);
}

void TestCase_1004()
{
    vector<int> nums1;
    int expect, out;

    nums1 = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    expect = 10;
    out = longestOnes(nums1.data(), (int)nums1.size(), 3);
    COMPVALUE(expect, out);

    nums1 = { 1,1,1,0,0,0,1,1,1,1,0 };
    expect = 6;
    out = longestOnes(nums1.data(), (int)nums1.size(), 2);
    COMPVALUE(expect, out);
}

void TestCase_9999()
{
    string src, word;
    int expect, out;

    src = "mdlldltxdy";
    word = "mdl";
    expect = 4;
    out = FindSubFrequence(&*src.begin(), &*word.begin());
    COMPVALUE(expect, out);

    src = "mmmdddllltql";
    word = "mdl";
    expect = 36;
    out = FindSubFrequence(&*src.begin(), &*word.begin());
    COMPVALUE(expect, out);
}
void TestCase_947()
{
    vector<vector<int>> stones;
    int** p;
    int size, col;

    stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    size = (int)stones.size(), col = 2;
    p = matrix2addr(stones);
    removeStones(p, size, &col);
}
void TestCase_227()
{
    string s ;
    int expect;
    int out;

    s = "14/3*2";
    expect = 8;
    out = calculateII(&*s.begin());
    COMPVALUE(expect, out);

    s = "12-3*4";
    expect = 0;
    out = calculateII(&*s.begin());
    COMPVALUE(expect, out);

    s = "3+2*2";
    expect = 7;
    out = calculateII(&*s.begin());
    COMPVALUE(expect, out);
}

void TestCase_735()
{
    vector<int> nums1;
    int count;
    nums1 = { 1,-2,-2,-2 };
    asteroidCollision(nums1.data(), (int)nums1.size(), &count);
}

void TestCase_322()
{
    vector<int> nums1;
    int expect, out, amount = 11;
    nums1 = { 1,2,5 };
    expect = 3;
    out = coinChange(nums1.data(), (int)nums1.size(), 11);
    COMPVALUE(expect, out);
}

void TestCase_1035()
{
    vector<int> nums1, nums2;
    int expect, out;
    nums1 = { 1,4,2 };
    nums2 = { 1,2,4 };
    expect = 2;
    out = maxUncrossedLines(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size());
    COMPVALUE(expect, out);

    nums1 = { 2,5,1,2,5 };
    nums2 = { 10,5,2,1,5,2 };
    expect = 3;
    out = maxUncrossedLines(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size());
    COMPVALUE(expect, out);

    nums1 = { 1,3,7,1,7,5 };
    nums2 = { 1,9,2,5,1 };
    expect = 2;
    out = maxUncrossedLines(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size());
    COMPVALUE(expect, out);
}
void TestCase_417()
{
    vector<vector<int>> matrix;
    int** p;
    int row, col;
    int rrow, rcol;
    int* rrcol = &rcol;

    matrix = { {1} };
    row = 1, col = 1;
    p = matrix2addr(matrix);
    pacificAtlantic(p, row, &col, &rrow, &rrcol);

    matrix = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5} ,{5,1,1,2,4} };
    row = 5, col =5;
    p = matrix2addr(matrix);
    pacificAtlantic(p, row, &col, &rrow, &rrcol);
}
void TestCase_621()
{
    string tasks = "AAABBB";
    int n, out, exp;

    /*tasks = "AAABBB";
    n = 2;
    exp = 8;
    out = leastInterval(&*tasks.begin(), (int)tasks.length(), 2);
    COMPVALUE(exp, out);*/

    tasks = "AAAAAABCDEFG";
    n = 2;
    exp = 16;
    out = leastInterval(&*tasks.begin(), (int)tasks.length(), 2);
    COMPVALUE(exp, out);
}

void TestCase_2215()
{
    vector<int> nums1,nums2;
    int nr = 0, nl;
    int* nnl = &nl;
    nums1 = { 11,-9,-6,-8,0,-6,2,10,1,-5,-9 };
    nums2 = { 10,1,-2,-7,8,-1,-6,8,-11,8,7 };
    //findDifference(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &nr, &nnl);
    findDifference(nums1, nums2);
}

void TestCase_300()
{
    vector<int> nums;
    nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    int res = lengthOfLIS(nums.data(), (int)nums.size());
}
void TestCase_55()
{
    vector<int> nums;
    bool ans1, ans2;
    nums = { 2,3,1,1,4 };
    ans1 = canJump(nums.data(), (int)nums.size());
    nums = { 3,2,1,0,4 };
    ans2 = canJump(nums.data(), (int)nums.size());
}

void TestCase_213()
{
    vector<int> nums;
    nums = { 1,3,1,3,100 };
    int ans1,ans2;
    ans1 = rob2(nums.data(), (int)nums.size());
    ans2 = robCCC(nums);
}

void TestCase_946()
{
    vector<int> pushed, poped;
    pushed = { 1,2,3,4,5 };
    poped = { 4,5,3,2,1 };
    validateStackSequences(pushed.data(), (int)pushed.size(), poped.data(), (int)poped.size());
}

void TestCase_239()
{
    vector<int> nums;// = { 1,3,-1,-3,5,3,6,7 };
    int i;
    int k = 3;
    int* result;
    int resnum = 0;

    nums = { 1,3,-1,-3,5,3,6,7 };
    result = maxSlidingWindow(nums.data(), (int)nums.size(), k, &resnum);
    for (i = 0; i < (int)nums.size(); i++)
        printf("%6d", nums[i]);
    printf("\r\n");
    for (i = 0; i < resnum; i++)
        printf("%6d", result[i]);
    printf("\r\n");

    nums = { 9, 10, 9, -7, -4, -8, 2, -6 };
    k = 5;
    result = maxSlidingWindow(nums.data(), (int)nums.size(), k, &resnum);
    for (i = 0; i < (int)nums.size(); i++)
        printf("%6d", nums[i]);
    printf("\r\n");
    for (i = 0; i < resnum; i++)
        printf("%6d", result[i]);
    printf("\r\n");
    
}

void TestCase_150()
{
    vector<string> tokens;
    tokens = { "4","13","5","/","+" };
    evalRPN(tokens);
    /*char* result;
    string s = "We are happy.";
    result = replacespace(&*s.begin());
    printf("%s\r\n%s", s.c_str(), result);*/
}

void TestCase_8005()
{
    char* result;
    string s = "We are happy.";
    result = replacespace(&*s.begin());
    printf("%s\r\n%s", s.c_str(), result);
}

void TestCase_7()
{
    int x = 123;
    int result = 0;

    result = reverse(x);
    COMPVALUE(321, result);

    x = 120;
    result = reverse(x);
    COMPVALUE(21, result);

    x = -123;
    result = reverse(x);
    COMPVALUE(-321, result);

    x = 1534236469;
    result = reverse(x);
    COMPVALUE(9646324351, result);
}

void TestCase_39()
{
    vector<int> candidates = { 2,3,6,7 };
    int target = 7;
    int rrow, rcol;
    int* rrcol = &rcol;

    combinationSum(candidates.data(),(int)candidates.size(), target, &rrow, &rrcol);
}

void TestCase_40()
{
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    int rrow, rcol;
    int* rrcol = &rcol;

    combinationSum2(candidates.data(), (int)candidates.size(), target, &rrow, &rrcol);

    candidates = { 2, 5, 2, 1, 2 };
    target = 5;
    combinationSum2(candidates.data(), (int)candidates.size(), target, &rrow, &rrcol);
}

void TestCase_17()
{
    int count = 0;
    string digits = "7";
    letterCombinations(&*digits.begin(), &count);
}
void TestCase_1071()
{
    char* result;
    string s1 = "ABCABC", s2 = "ABC";
    result = gcdOfStrings(&*s1.begin(), &*s2.begin());
    printf("%s", result);

    s1 = "ABABAB", s2 = "ABAB";
    result = gcdOfStrings(&*s1.begin(), &*s2.begin());
    printf("%s", result);

    s1 = "LETF", s2 = "CODE";
    result = gcdOfStrings(&*s1.begin(), &*s2.begin());
    printf("%s", result);
}

void TestCase_216()
{
    int rrow, rcol;
    int* rrcol = &rcol;

    combinationSum3(3, 15, &rrow, &rrcol);
}

void TestCase_78()
{
    int nums[3] = { 1,2,3 };
    int rrow, rcol;
    int* rrcol = &rcol;

    subsets(&nums[0], 3, &rrow, &rrcol);
}

void TestCase_797()
{
    int** p = NULL;
    int i;
    int col[4] = { 2,1,1,0 };
    int rrow, rcol;
    int* rrcol = &rcol;
    p = (int**)malloc(4 * sizeof(int*));
    for (i = 0; i < 4; i++)
        p[i] = (int*)calloc(4, sizeof(int));
    p[0][0] = { 1 };
    p[0][1] = { 2 };
    p[1][0] = { 3 };
    p[2][0] = { 3 };

    allPathsSourceTarget(p, 4, &col[0], &rrow, &rrcol);
}
void TestCase_130()
{
    vector<vector<char>> matrix;
    char** p;
    /*int row=4, col=4;
    matrix = { {'X','X','X','X'} ,{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};*/
    int row = 2, col = 2;
    matrix = { {'0','0'} ,{'0','0'} };
    p = (char**)malloc(sizeof(char*) * row);
    for (int i = 0; i < row; i++) {
        p[i] = (char*)malloc(sizeof(char) * col);
        for (int j = 0; j < col; j++) {
            p[i][j] = matrix[i][j];
        }
    }

    solve(p, row, &col);
}

void TestCase_1091()
{
    vector<vector<int>> matrix;
    int** p;
    int row , col ;
    int expect, output;

    matrix = { {0, 1, 0, 0, 0, 0},{0, 1, 0, 1, 1, 0},{0, 1, 1, 0, 1, 0},{0, 0, 0, 0, 1, 0} ,{1, 1, 1, 1, 1, 0},{1, 1, 1, 1, 1, 0} };
    row = 6, col = 6;
    expect = 14;
    p = matrix2addr(matrix);
    output = shortestPathBinaryMatrix(p, row, &col);
    COMPVALUE(expect, output);

    matrix = { {0, 0, 0},{1, 1, 0},{1, 1, 0 }};
    row = 3, col = 3;
    expect = 4;
    p = matrix2addr(matrix);
    output = shortestPathBinaryMatrix(p, row, &col);
    COMPVALUE(expect, output);
}
void TestCase_1143()
{
    string text1, text2;

    text1 = "bl";
    text2 = "yby";

    longestCommonSubsequence(&*text1.begin(), &*text2.begin());
}

void TestCase_713()
{
    vector<int> nums;
    int expect, output;

    nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
    expect = 18;
    output = numSubarrayProductLessThanK(nums.data(), (int)nums.size(), 19);
    COMPVALUE(expect, output);

    nums = { 10,5,2,6 };
    expect = 8;
    output = numSubarrayProductLessThanK(nums.data(), (int)nums.size(), 100);
    COMPVALUE(expect, output);
}
void TestCase_153()
{
    vector<int> nums;
    int expect, output;

    nums = { 2,3 };
    expect = 2;
    output = findMin(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 11,13,15,17 };
    expect = 11;
    output = findMin(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 3,1,2 };
    expect = 1;
    output = findMin(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 4,5,6,7,0,1,2,3 };
    expect = 0;
    output = findMin(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);
}
void TestCase_1657()
{
    string word1, word2;
    bool expect, output;

    word1 = "cabbba";
    word2 = "aabbss";
    expect = false;
    output = closeStrings(&*word1.begin(), &*word2.begin());
    COMPVALUE(expect, output);
}

void TestCase_297()
{
    vector<int> num;
    struct TreeNode* root = NULL;
    char* ser;
    struct TreeNode* deser;

    num = { 7,3,6,8,2,3,6,4,7,6,5,1,-1001,3,-1001,8,7,9,9,6,5,3,3,0,-1001,0,0,0,-1001,1,6,2,6,7,0,9,-1001,8,-1001,5,2,2,6,3,-1001,3,2,9,0,5,2,-1001,8,7,0,8,-1001,6,9,8,5,9,1,9,0,8,8,0,5,-1001,5,1,8,8,0,3,3,4,6,7,-1001,1,-1001,-1001,-1001,8,3,0,6,2,-1001,6,8,-1001,9,5,8,5,0,6,6,1,7,0,8,9,7,2,1,5,8,6,9,1,-1001,6,-1001,-1001,4,7,0,6,9,3,3,9,2,1,3,7,7,9,9,1,5,5,-1001,3,4,4,6,3,2,6,1,4,0,4,4,4,9,7,2,8,6,6,-1001,1,9,2,6,1,1,-1001,8,6,1,1,7,7,6,7,1,0,4,1,3,4,4,-1001,-1001,4,1,8,7,5,6,-1001,2,5,6,9,7,-1001,8,6,7,-1001,9,8,9,9,9,1,-1001,7,-1001,7,7,8,0,8,5,1,-1001,2,6,7,9,5,2,8,-1001,2,-1001,7,5,5,-1001,2,-1001,0,7,-1001,-1001,-1001,5,5,9,9,-1001,0,1,-1001,5,-1001,5,6,5,-1001,1,3,9,-1001,1,9,0,6,8,7,2,1,4,4,7,7,8,0,8,3,7,7,8,7,3,7,6,7,5,5,9,7,-1001,9,9,1,3,2,2,5,6,2,4,3,-1001,5,-1001,5,3,1,-1001,0,6,0,8,6,1,1,3,4,3,0,8,7,-1001,-1001,6,-1001,-1001,2,7,0,-1001,2,-1001,1,6,7,6,3,-1001,-1001,0,5,5,0,7,3,6,5,3,2,5,-1001,9,2,7,0,5,-1001,9,1,5,-1001,3,1,7,-1001,6,5,3,5,-1001,6,5,5,9,0,0,2,6,3,9,3,2,3,0,4,-1001,7,0,5,1,7,5,4,2,-1001,5,8,9,9,0,9,9,6,8,2,0,-1001,1,-1001,0,-1001,1,5,3,8,1,6,3,8,-1001,0,8,-1001,3,9,5,1,6,4,7,8,0,8,7,9,9,2,-1001,3,6,1,0,6,4,1,7,6,-1001,9,5,7,1,2,6,-1001,2,-1001,0,9,-1001,8,8,3,7,0,3,5,3,8,4,7,2,3,7,5,7,3,5,6,2,7,7,-1001,0,5,7,4,1,-1001,0,-1001,6,0,7,-1001,2,4,7,8,6,1,0,9,1,9,4,3,2,0,-1001,4,9,4,1,7,5,8,-1001,9,0,2,-1001,4,3,1,2,4,2,6,2,5,1,-1001,0,0,7,8,9,7,6,-1001,-1001,3,-1001,7,2,0,5,8,-1001,2,-1001,0,5,1,1,4,1,2,5,8,9,2,5,0,-1001,2,8,-1001,-1001,2,4,0,6,4,-1001,8,0,6,8,2,-1001,4,4,0,2,0,9,6,2,-1001,-1001,6,0,2,9,5,9,7,0,9,3,-1001,8,5,5,-1001,4,1,5,8,3,3,7,-1001,8,-1001,8,-1001,9,4,-1001,2,7,2,8,8,6,7,5,3,9,6,4,0,-1001,5,0,8,7,8,-1001,5,9,6,-1001,6,6,5,2,3,9,8,1,2,0,2,1,-1001,8,8,-1001,8,4,-1001,1,-1001,0,0,1,8,7,7,9,8,9,-1001,7,1,-1001,7,9,3,9,-1001,7,3,7,-1001,8,1,2,8,3,4,-1001,5,7,0,6,7,1,-1001,-1001,1,-1001,8,4,3,6,0,9,-1001,2,3,0,3,8,-1001,6,-1001,-1001,7,2,7,9,-1001,4,9,4,-1001,8,-1001,3,4,6,0,0,2,8,1,5,0,7,1,3,0,4,4,5,3,0,0,2,1,5,5,1,3,8,3,-1001,6,8,1,2,-1001,0,9,2,-1001,-1001,8,8,-1001,4,9,6,9,8,8,5,1,5,0,6,6,0,9,-1001,5,-1001,4,2,-1001,9,0,4,7,7,1,-1001,-1001,-1001,5,9,8,-1001,-1001,5,5,8,-1001,9,7,0,0,2,4,0,1,3,5,8,-1001,9,7,6,8,6,0,1,9,9,4,3,3,0,5,-1001,-1001,7,8,5,-1001,9,6,1,6,7,2,7,3,5,8,4,4,8,-1001,7,-1001,3,8,0,2,8,8,2,1,8,4,1,-1001,-1001,7,1,0,0,7,5,6,-1001,0,7,-1001,0,-1001,4,8,4,-1001,-1001,6,2,0,-1001,5,4,8,3,-1001,3,6,8,2,5,6,-1001,1,1,4,1,-1001,7,2,8,7,6,5,-1001,9,7,9,1,4,-1001,4,9,-1001,3,1,-1001,-1001,9,7,-1001,0,8,4,4,8,2,7,0,0,4,7,1,-1001,9,2,4,5,-1001,5,4,4,3,9,8,1,3,3,1,0,4,5,8,6,0,0,-1001,-1001,1,1,0,9,3,0,4,-1001,2,1,9,1,4,0,5,2,0,-1001,1,1,8,7,9,8,2,9,2,7,5,3,3,6,7,-1001,2,0,9,5,9,-1001,6,-1001,6,3,1,3,0,0,8,0,2,4,3,2,9,7,-1001,2,2,2,-1001,2,4,9,2,0,-1001,5,-1001,3,7,0,1,3,3,8,4,0,9,3,2,6,-1001,5,9,5,6,3,3,2,0,4,3,0,0,5,-1001,7,-1001,4,1,1,9,-1001,-1001,0,4,5,7,2,6,8,8,-1001,-1001,2,3,8,2,2,3,2,7,2,2,-1001,2,9,0,9,0,6,6,1,5,-1001,-1001,8,8,9,7,5,0,6,-1001,9,4,8,0,2,7,5,1,4,8,5,9,3,6,0,5,3,-1001,0,3,0,5,8,7,2,3,6,8,6,9,0,4,6,1,3,1,3,2,3,5,6,3,8,7,3,3,6,5,1,2,2,9,4,3,3,0,4,-1001,4,4,2,-1001,-1001,7,-1001,5,2,2,1,0,3,-1001,1,2,3,0,6,2,7,2,9,5,9,1,3,5,8,9,-1001,5,0,5,1,-1001,2,7,0,8,4,6,-1001,2,2,8,5,-1001,4,5,8,8,7,9,0,8,9,9,0,4,8,6,3,8,5,0,1,1,0,8,4,7,-1001,1,-1001,6,2,2,9,9,8,2,3,5,6,4,8,-1001,-1001,4,-1001,1,6,2,3,-1001,3,-1001,7,5,-1001,9,2,0,7,4,2,0,7,0,2,9,1,1,8,0,3,9,7,0,0,2,5,9,-1001,3,-1001,-1001,4,9,-1001,0,5,0,6,8,0,0,9,0,3,1,-1001,7,7,0,0,9,1,7,8,2,-1001,6,9,1,0,1,8,1,9,8,8,8,5,6,3,5,7,0,7,7,9,6,-1001,-1001,1,8,-1001,2,7,6,7,4,6,4,1,2,2,1,2,1,-1001,7,8,7,-1001,3,1,5,-1001,3,9,1,3,5,3,7,7,3,-1001,0,2,4,9,3,7,7,5,-1001,0,0,-1001,5,0,7,6,2,8,2,-1001,4,-1001,2,7,-1001,-1001,7,3,4,1,7,8,2,6,4,7,8,7,8,3,4,9,3,6,9,6,5,9,0,6,5,4,9,4,2,7,1,1,2,0,5,2,9,-1001,5,6,1,7,0,7,-1001,9,7,9,9,-1001,-1001,8,1,2,2,9,9,3,7,-1001,2,0,3,-1001,-1001,6,5,-1001,7,-1001,0,4,1,3,-1001,6,7,4,0,5,1,-1001,8,-1001,8,2,1,2,3,2,9,8,3,-1001,3,4,1,5,1,7,3,-1001,4,3,5,7,9,4,2,-1001,1,4,3,-1001,9,7,-1001,2,-1001,1,2,2,3,8,8,3,1,5,1,-1001,6,1,5,5,0,-1001,1,-1001,8,9,3,8,7,5,4,0,9,9,5,-1001,4,-1001,-1001,1,0,1,0,3,-1001,0,7,1,2,5,4,2,1,3,9,-1001,-1001,-1001,1,5,6,4,-1001,3,0,4,0,1,3,6,-1001,0,6,5,-1001,2,-1001,7,-1001,-1001,-1001,-1001,1,3,4,7,5,-1001,-1001,0,3,8,0,-1001,3,1,7,3,-1001,2,9,9,1,-1001,9,-1001,4,5,-1001,7,0,-1001,5,9,2,6,2,4,3,0,3,0,7,3,7,4,4,1,9,3,2,3,7,2,-1001,6,8,1,2,0,0,1,6,5,5,6,7,4,7,8,6,2,8,8,6,4,5,8,4,0,5,3,1,-1001,1,9,6,-1001,-1001,9,3,6,8,3,5,0,-1001,6,5,8,-1001,1,-1001,9,2,5,1,5,1,-1001,8,-1001,-1001,6,3,6,4,1,-1001,2,1,2,9,8,4,3,2,5,-1001,0,5,6,-1001,-1001,2,1,6,4,4,9,1,9,9,3,6,3,3,0,5,7,0,7,2,4,0,9,6,5,-1001,1,0,4,9,3,4,4,0,-1001,9,2,0,7,3,8,0,8,3,4,6,-1001,7,8,2,7,3,1,9,3,3,4,4,-1001,3,4,-1001,-1001,8,8,9,9,-1001,5,-1001,1,5,7,0,9,6,1,8,8,7,7,-1001,-1001,0,3,0,-1001,8,4,5,0,9,5,7,-1001,5,0,8,7,8,0,2,4,4,3,9,0,8,4,3,4,3,8,6,2,1,5,-1001,-1001,0,2,4,0,6,5,2,8,7,2,9,1,7,-1001,5,0,-1001,-1001,-1001,7,4,1,5,8,6,-1001,7,0,3,8,2,9,8,1,-1001,0,7,-1001,2,-1001,8,7,6,5,1,1,7,9,7,3,7,-1001,5,-1001,2,4,6,8,-1001,0,4,5,8,-1001,7,5,9,1,-1001,-1001,5,8,5,0,-1001,-1001,1,1,0,2,0,4,5,3,3,8,0,4,-1001,2,3,8,-1001,9,5,4,4,6,5,4,7,2,0,1,-1001,4,8,9,0,7,8,2,8,0,5,4,6,2,8,5,2,6,7,5,9,0,4,-1001,6,9,2,0,2,6,-1001,-1001,-1001,7,2,2,7,0,9,-1001,9,9,-1001,1,6,-1001,3,9,1,9,6,5,0,0,3,8,6,2,0,2,-1001,7,-1001,8,1,3,7,-1001,1,-1001,6,9,3,6,8,2,8,4,3,6,6,8,-1001,3,1,1,8,3,0,9,6,-1001,5,7,5,-1001,9,2,1,7,3,7,3,-1001,3,2,-1001,2,-1001,4,4,9,0,1,8,5,5,1,7,5,3,0,8,5,3,6,6,5,-1001,3,6,7,8,-1001,0,1,6,5,-1001,5,7,3,1,2,6,3,-1001,6,1,7,4,9,3,3,1,1,8,4,6,-1001,1,2,0,-1001,7,9,4,6,0,7,3,4,7,3,0,1,9,6,8,2,7,-1001,-1001,7,1,2,1,0,8,8,8,2,0,3,7,3,1,8,-1001,5,3,2,8,7,8,-1001,-1001,8,9,9,7,-1001,-1001,7,4,7,4,-1001,7,7,9,3,-1001,3,0,6,0,5,7,2,2,6,4,3,-1001,7,0,6,9,9,5,2,3,6,7,-1001,8,2,-1001,6,-1001,8,4,1,2,0,3,-1001,4,9,7,3,9,4,8,6,0,0,-1001,5,-1001,2,0,3,1,9,0,8,8,-1001,9,8,8,7,2,0,5,4,4,5,0,2,2,6,8,5,3,5,8,9,8,6,9,4,7,4,3,2,4,1,9,9,0,2,9,-1001,-1001,4,3,-1001,-1001,5,7,1,6,3,5,9,-1001,1,-1001,2,4,9,1,8,3,2,-1001,7,7,3,8,5,1,3,5,9,-1001,8,8,2,6,9,0,2,5,1,7,6,0,2,0,7,6,-1001,0,3,9,6,9,5,6,1,-1001,3,7,-1001,6,2,3,4,9,5,4,-1001,-1001,1,-1001,4,7,5,9,-1001,4,0,4,7,4,1,6,7,7,0,5,1,8,1,3,2,3,4,3,2,9,8,2,8,2,0,8,6,1,4,9,9,9,7,5,8,0,6,4,3,0,-1001,-1001,4,4,-1001,-1001,5,-1001,5,1,0,5,-1001,8,5,-1001,-1001,6,1,1,0,7,8,2,8,7,8,9,8,-1001,6,7,9,1,0,3,7,-1001,-1001,3,0,2,1,8,1,3,6,9,1,-1001,6,-1001,7,7,5,6,1,8,0,2,1,5,1,5,-1001,7,6,-1001,2,4,-1001,5,1,0,8,7,3,9,7,7,6,7,-1001,2,9,7,0,8,5,9,3,3,-1001,6,2,2,5,0,-1001,1,5,5,6,3,1,4,2,-1001,8,9,3,7,3,6,6,5,6,0,9,4,5,4,3,3,3,-1001,7,7,-1001,8,-1001,5,8,9,1,9,0,4,9,7,2,8,3,6,3,1,8,-1001,3,3,1,8,8,5,3,2,0,7,5,6,9,2,3,1,4,9,9,0,-1001,7,8,1,3,8,2,7,8,7,6,7,8,5,7,-1001,7,2,2,0,9,6,0,1,8,4,1,0,4,5,5,0,0,8,9,2,8,0,1,6,6,0,4,-1001,7,1,-1001,1,0,6,0,-1001,2,6,-1001,-1001,1,-1001,7,1,6,4,-1001,5,2,9,5,8,2,6,0,5,9,5,7,9,-1001,4,-1001,1,-1001,1,6,-1001,-1001,1,0,-1001,-1001,7,7,6,3,4,9,4,9,4,9,5,5,-1001,3,6,4,6,8,7,0,1,9,9,-1001,0,7,1,5,-1001,2,6,8,1,0,2,8,6,-1001,8,8,3,-1001,2,0,6,-1001,7,8,7,8,-1001,8,-1001,5,0,7,7,0,0,3,-1001,-1001,8,-1001,9,4,4,1,5,2,0,2,8,1,0,7,0,8,2,5,-1001,2,6,-1001,0,-1001,-1001,5,4,7,-1001,0,-1001,1,1,7,5,9,1,1,9,5,-1001,8,8,6,1,8,9,-1001,9,6,2,3,-1001,8,3,8,5,6,1,1,-1001,7,9,3,3,3,5,2,7,7,9,5,-1001,5,9,-1001,6,-1001,9,0,7,8,6,4,8,0,-1001,-1001,1,3,6,8,-1001,9,-1001,-1001,8,-1001,-1001,5,-1001,3,4,-1001,9,9,9,-1001,3,1,1,3,1,8,3,4,6,8,7,5,9,2,-1001,3,5,-1001,3,-1001,5,4,1,8,8,4,0,3,2,0,1,4,9,-1001,6,5,-1001,1,0,6,3,8,7,-1001,2,1,5,2,8,3,5,5,1,-1001,3,7,4,6,6,6,4,8,9,4,-1001,8,-1001,7,-1001,6,4,8,6,-1001,6,9,0,3,3,-1001,4,7,7,7,1,4,3,-1001,5,9,8,-1001,-1001,1,6,3,2,3,6,2,5,1,8,9,3,1,1,9,4,4,-1001,8,7,7,2,1,9,3,0,1,3,0,3,9,3,1,2,8,-1001,6,7,9,2,8,9,0,3,2,-1001,6,4,3,-1001,9,8,0,5,6,0,2,8,5,9,4,2,3,4,4,6,9,4,8,0,3,6,2,0,2,1,-1001,0,3,4,-1001,3,7,1,-1001,0,-1001,1,0,7,5,5,9,0,9,7,0,8,0,0,1,-1001,6,6,1,5,-1001,1,0,3,4,1,-1001,-1001,4,-1001,-1001,7,7,-1001,7,7,4,9,5,8,1,-1001,1,7,0,8,-1001,9,-1001,-1001,0,9,-1001,2,-1001,5,-1001,9,3,2,1,6,6,5,2,3,7,9,-1001,4,8,8,-1001,2,-1001,-1001,1,4,5,9,6,3,-1001,4,-1001,-1001,0,-1001,1,5,1,9,-1001,1,5,-1001,2,3,2,-1001,5,3,-1001,3,3,5,7,2,1,-1001,6,7,8,7,4,1,-1001,6,0,1,4,6,2,3,1,7,7,0,2,8,7,9,5,1,3,8,3,1,6,9,4,7,3,6,2,0,-1001,-1001,2,8,6,9,2,-1001,-1001,1,3,2,9,-1001,7,-1001,-1001,9,7,-1001,-1001,7,2,9,4,8,6,4,1,7,3,8,5,4,5,-1001,9,5,7,8,7,0,6,7,7,-1001,2,3,6,3,7,8,8,0,7,-1001,3,6,2,6,2,6,6,7,5,0,9,1,9,8,9,-1001,-1001,5,8,2,5,8,-1001,5,3,-1001,2,7,7,-1001,3,5,3,3,0,7,6,0,9,9,2,3,6,3,4,9,-1001,7,1,5,4,7,-1001,1,2,9,8,9,-1001,2,3,4,1,2,2,1,4,0,9,0,8,0,2,1,8,0,2,2,6,3,3,-1001,3,-1001,0,4,8,9,1,4,6,4,4,-1001,0,0,7,-1001,5,4,2,2,2,3,3,4,7,6,-1001,8,4,7,-1001,6,9,7,2,2,0,4,-1001,2,3,7,8,0,-1001,6,-1001,1,4,6,4,7,6,9,3,4,2,-1001,2,3,-1001,7,7,7,5,4,9,8,-1001,4,2,7,-1001,7,4,2,8,8,9,9,8,6,4,8,3,6,4,0,4,-1001,1,6,7,7,3,-1001,0,6,7,9,2,5,9,6,2,9,3,7,5,-1001,3,5,9,3,-1001,4,2,0,-1001,0,-1001,0,-1001,1,4,-1001,5,5,4,8,5,-1001,-1001,2,7,0,2,-1001,7,4,8,7,8,2,0,0,7,-1001,-1001,6,7,-1001,8,5,0,-1001,6,0,1,4,-1001,-1001,9,1,-1001,0,4,6,4,4,9,4,0,7,7,3,9,-1001,-1001,9,5,3,6,-1001,9,2,1,0,6,-1001,6,5,3,-1001,7,4,1,9,-1001,6,9,2,1,6,-1001,8,6,-1001,4,0,5,0,8,2,7,9,4,6,3,9,9,9,1,0,-1001,8,6,4,8,2,0,0,8,6,0,-1001,2,3,-1001,9,7,4,8,9,8,1,9,0,8,9,-1001,-1001,1,7,3,-1001,8,7,4,6,8,8,5,-1001,9,5,8,6,2,8,2,1,-1001,0,9,-1001,5,1,-1001,2,6,3,4,2,0,3,5,4,-1001,-1001,8,-1001,8,8,0,8,1,3,9,5,2,5,0,2,-1001,6,1,9,6,6,5,7,5,-1001,2,5,9,-1001,7,9,-1001,6,7,5,8,7,8,0,4,7,-1001,0,0,-1001,6,3,3,-1001,7,1,8,2,4,9,9,7,4,7,5,1,3,8,0,1,9,8,9,2,-1001,8,-1001,6,3,0,2,4,7,3,5,5,4,3,1,6,2,1,1,3,7,3,9,7,9,6,8,9,5,5,6,9,9,8,-1001,9,0,0,-1001,0,8,-1001,0,4,8,-1001,1,6,9,1,5,4,4,5,3,5,-1001,9,9,9,9,5,4,0,7,4,8,1,0,3,1,4,6,9,-1001,9,7,4,7,3,7,5,3,-1001,-1001,9,5,2,6,-1001,9,4,0,-1001,7,2,3,7,6,2,0,1,7,1,3,1,6,8,-1001,9,5,-1001,4,-1001,5,2,5,-1001,2,-1001,2,4,2,4,5,3,-1001,8,3,1,9,3,4,-1001,2,2,2,4,-1001,3,7,1,-1001,1,4,6,1,8,-1001,8,4,2,5,3,7,2,3,8,4,5,8,-1001,3,1,-1001,0,4,4,0,6,3,1,0,2,9,9,3,-1001,8,0,6,4,1,2,1,5,1,6,7,9,-1001,4,6,1,8,6,3,9,-1001,3,2,2,6,0,6,2,0,0,6,5,1,9,7,2,3,-1001,4,1,1,7,8,2,1,-1001,9,4,-1001,-1001,7,7,5,2,9,9,5,0,8,1,6,7,0,2,1,-1001,0,9,4,6,-1001,-1001,8,5,6,6,4,2,-1001,8,2,-1001,7,4,-1001,-1001,-1001,-1001,3,6,-1001,0,-1001,5,-1001,1,8,1,0,5,6,5,6,0,0,7,2,-1001,7,-1001,8,9,0,8,8,9,-1001,2,8,2,9,3,-1001,-1001,3,1,4,0,6,3,-1001,4,-1001,8,7,7,-1001,7,0,5,1,0,7,9,8,2,7,8,1,0,6,5,0,5,-1001,3,5,2,-1001,-1001,6,-1001,1,3,-1001,5,2,8,5,9,2,5,3,6,-1001,6,0,-1001,5,1,0,8,2,0,7,0,8,2,6,-1001,4,0,5,-1001,7,4,4,5,6,1,5,4,4,9,0,0,9,2,4,1,2,9,6,0,0,9,1,7,2,4,9,4,0,7,4,3,2,5,1,0,8,-1001,1,2,-1001,1,8,9,8,8,2,9,5,0,3,0,4,6,8,-1001,5,2,5,7,9,2,4,4,0,1,8,-1001,5,9,8,0,-1001,2,7,8,9,7,-1001,7,8,-1001,-1001,4,-1001,9,2,1,1,0,1,6,5,8,3,5,8,7,9,2,5,1,4,6,-1001,6,0,4,9,8,0,8,4,6,1,8,4,3,-1001,4,5,6,-1001,2,-1001,9,8,7,7,1,9,8,8,6,0,1,6,6,3,1,6,1,0,2,-1001,1,5,0,8,-1001,7,-1001,4,5,7,-1001,8,-1001,1,9,7,2,2,-1001,0,7,6,1,-1001,1,-1001,4,1,0,5,1,3,5,5,1,2,9,5,-1001,9,6,5,1,1,8,2,2,4,-1001,6,8,-1001,6,4,0,-1001,5,0,3,3,1,7,1,3,3,8,7,-1001,9,0,-1001,9,3,9,-1001,-1001,7,-1001,3,0,3,-1001,7,-1001,1,6,-1001,6,-1001,1,3,9,7,1,1,4,5,9,8,9,6,1,0,-1001,8,3,4,2,5,6,4,-1001,2,-1001,2,2,9,2,4,1,7,9,2,2,0,0,5,-1001,0,7,9,-1001,2,-1001,-1001,0,-1001,6,9,-1001,8,5,4,-1001,-1001,8,5,2,-1001,-1001,2,0,-1001,1,8,7,-1001,9,6,3,0,9,7,8,5,1,4,8,7,8,0,-1001,0,7,5,8,2,-1001,8,2,4,4,-1001,5,0,1,8,7,3,9,6,2,5,5,1,3,3,8,3,1,2,4,-1001,0,8,3,7,2,-1001,-1001,1,7,0,0,6,4,2,0,6,6,4,7,7,6,2,1,1,6,2,7,8,-1001,9,-1001,9,0,9,7,5,4,2,6,-1001,1,0,4,8,6,5,0,9,8,9,3,3,-1001,8,2,3,5,-1001,1,6,6,3,8,5,-1001,1,3,5,5,6,2,0,3,-1001,6,4,7,-1001,3,2,3,9,5,0,7,9,3,7,3,8,4,2,-1001,9,4,6,-1001,7,6,8,3,6,0,6,-1001,9,5,-1001,-1001,1,1,5,2,8,4,1,0,1,4,5,7,4,6,4,-1001,0,7,-1001,9,-1001,4,0,9,5,4,2,1,2,-1001,5,4,-1001,-1001,8,6,8,6,-1001,3,6,9,8,3,2,0,3,2,5,9,-1001,-1001,1,-1001,6,0,0,5,9,2,4,-1001,2,3,3,5,4,6,-1001,4,8,-1001,2,5,0,-1001,-1001,1,-1001,5,2,-1001,8,9,2,7,1,4,3,6,6,9,7,7,-1001,9,-1001,7,-1001,5,9,0,5,7,4,8,4,2,4,6,8,1,-1001,8,5,-1001,3,7,7,9,5,3,-1001,-1001,1,0,1,8,6,3,2,1,8,-1001,0,3,6,3,1,7,9,9,1,2,5,0,7,1,7,6,9,8,7,2,4,0,3,7,5,4,9,6,-1001,0,8,2,3,5,-1001,4,1,7,5,7,7,8,7,9,-1001,7,3,-1001,1,2,6,5,8,9,2,3,8,0,0,9,-1001,4,0,3,3,-1001,4,6,0,-1001,4,5,7,5,8,2,0,-1001,7,1,-1001,2,5,3,8,9,8,5,0,-1001,8,-1001,-1001,9,5,7,-1001,7,-1001,3,2,8,0,-1001,9,1,1,5,2,7,0,-1001,0,5,0,5,-1001,4,8,7,0,2,8,4,0,8,5,4,9,0,-1001,4,8,4,3,4,2,9,5,-1001,3,-1001,2,3,-1001,3,-1001,8,3,5,1,1,3,5,8,9,-1001,1,1,4,9,-1001,3,7,1,-1001,5,4,8,1,4,9,0,3,2,-1001,6,-1001,3,-1001,4,3,4,2,4,5,5,4,6,1,4,0,4,1,0,3,5,1,5,3,9,8,7,3,1,2,-1001,0,7,4,9,7,8,7,-1001,1,0,9,8,6,0,7,0,3,3,7,0,9,1,5,9,5,2,4,0,6,0,4,4,5,-1001,0,9,7,1,7,8,8,6,3,9,-1001,0,5,5,5,7,6,9,-1001,8,6,9,-1001,9,4,5,0,-1001,2,2,-1001,4,9,2,1,-1001,6,5,8,2,8,6,8,5,8,2,-1001,0,-1001,7,7,8,3,0,4,-1001,3,7,-1001,0,9,1,5,6,9,6,3,6,1,5,0,-1001,4,7,0,0,9,0,3,7,1,9,0,-1001,9,1,6,-1001,3,0,1,-1001,0,-1001,4,0,8,3,3,8,3,1,8,9,7,6,9,0,4,6,1,9,6,6,1,3,2,4,5,-1001,-1001,5,-1001,5,8,-1001,3,7,6,5,6,0,0,3,7,9,3,9,-1001,0,2,3,8,4,-1001,0,3,6,6,8,-1001,1,6,0,9,4,2,7,9,0,1,-1001,0,5,8,6,5,-1001,5,7,3,0,2,7,0,9,-1001,5,1,4,1,2,-1001,6,2,4,3,1,1,4,5,4,-1001,5,6,4,0,0,5,6,8,9,0,9,9,7,3,8,4,5,4,-1001,-1001,8,0,-1001,5,3,8,8,-1001,-1001,1,4,-1001,-1001,4,5,6,0,0,1,0,-1001,8,5,-1001,0,6,6,-1001,6,6,4,2,6,-1001,2,0,1,2,1,6,3,4,5,3,-1001,1,0,3,8,0,4,5,8,-1001,-1001,5,2,9,9,9,7,4,1,5,-1001,0,5,5,0,0,1,-1001,9,-1001,2,-1001,-1001,0,2,-1001,2,4,1,9,3,1,5,3,3,5,3,8,9,3,9,7,9,-1001,-1001,6,2,1,1,-1001,5,6,5,4,7,4,-1001,1,4,-1001,2,9,-1001,9,0,6,8,7,-1001,6,-1001,8,5,-1001,0,0,0,1,4,-1001,8,-1001,-1001,9,-1001,8,7,1,6,5,6,-1001,6,7,1,-1001,7,4,-1001,-1001,5,2,-1001,0,9,8,-1001,6,2,4,-1001,-1001,-1001,5,0,-1001,9,1,9,8,9,8,4,-1001,8,1,5,-1001,-1001,7,0,4,6,2,6,6,7,-1001,0,7,5,0,2,9,7,8,-1001,1,6,7,9,5,0,4,6,9,6,4,3,2,6,2,8,6,7,2,9,7,2,9,9,8,5,5,0,2,5,9,4,0,1,7,2,5,-1001,6,4,4,7,6,4,1,0,8,7,5,7,3,1,1,4,1,-1001,4,1,8,4,-1001,0,5,2,3,3,9,7,9,8,-1001,-1001,3,-1001,9,6,2,7,0,1,-1001,8,-1001,-1001,3,1,0,4,0,8,9,9,8,2,0,-1001,8,7,5,-1001,-1001,6,3,-1001,0,4,0,4,1,8,1,9,9,0,8,8,6,-1001,8,1,6,4,5,0,2,0,1,4,7,5,3,6,7,-1001,3,6,4,7,4,6,6,7,8,6,1,3,-1001,-1001,9,2,3,4,9,3,-1001,8,2,6,7,2,9,7,-1001,-1001,8,2,6,9,8,9,1,9,7,0,-1001,2,1,-1001,2,3,-1001,0,7,8,1,6,7,1,7,4,-1001,7,-1001,1,1,9,3,9,5,1,2,3,2,7,-1001,-1001,1,3,0,8,6,6,2,2,9,1,4,8,6,9,-1001,1,9,2,3,2,0,3,8,-1001,6,0,4,0,4,-1001,-1001,1,4,9,8,7,-1001,3,2,2,9,8,2,5,2,9,5,7,-1001,9,8,-1001,9,3,8,0,-1001,3,9,6,8,8,8,3,-1001,-1001,4,6,6,2,9,3,5,6,4,7,3,7,0,3,3,8,-1001,-1001,-1001,4,6,3,3,4,0,6,2,3,0,-1001,7,6,1,8,1,-1001,-1001,0,-1001,-1001,9,7,8,1,3,-1001,1,4,2,8,7,8,8,6,-1001,-1001,3,1,2,8,1,4,8,8,9,-1001,0,7,-1001,1,0,6,5,7,-1001,8,7,8,4,7,4,6,3,3,8,3,2,0,6,2,8,-1001,9,0,7,4,-1001,5,9,5,8,5,9,8,3,8,-1001,-1001,9,4,2,9,6,2,1,2,-1001,-1001,5,1,0,2,6,7,6,3,-1001,5,6,8,3,6,9,9,7,-1001,7,0,1,9,4,7,0,1,3,0,4,9,8,0,2,4,9,2,2,3,8,2,0,4,3,-1001,7,9,1,3,4,8,-1001,2,-1001,5,6,3,5,5,5,5,7,-1001,-1001,3,1,7,4,1,-1001,5,5,1,8,7,8,3,0,0,1,5,1,5,5,2,0,1,1,3,-1001,7,4,4,8,9,-1001,8,-1001,7,9,5,1,-1001,0,9,2,4,-1001,0,1,5,9,0,0,6,1,0,0,2,-1001,-1001,5,9,-1001,6,8,1,6,1,2,9,-1001,2,2,9,4,9,5,8,6,4,7,9,4,9,3,-1001,2,-1001,4,4,8,4,4,0,8,2,3,0,5,2,2,7,4,7,1,-1001,8,0,6,6,8,2,6,-1001,8,4,3,1,7,-1001,7,2,2,2,8,9,2,1,-1001,2,9,8,0,6,-1001,-1001,2,8,5,7,2,1,8,5,4,1,4,1,9,0,3,1,0,8,3,2,4,8,3,6,4,0,5,3,8,2,5,8,8,3,9,-1001,9,-1001,2,9,1,-1001,7,-1001,7,1,8,8,4,5,7,5,2,-1001,3,-1001,4,7,0,5,0,3,0,4,8,3,-1001,0,6,9,7,9,-1001,4,9,4,-1001,0,5,2,4,-1001,9,3,0,5,3,2,3,8,3,7,9,1,0,2,4,6,2,0,2,8,3,5,2,3,4,8,4,0,6,-1001,-1001,5,-1001,4,-1001,3,-1001,2,2,9,9,-1001,6,0,-1001,8,0,9,-1001,4,2,9,4,2,2,0,3,0,1,8,8,3,-1001,4,7,8,4,-1001,9,8,-1001,8,9,4,4,3,2,5,2,-1001,5,4,6,0,4,-1001,2,7,-1001,1,5,9,2,6,-1001,4,8,-1001,3,4,7,8,9,-1001,-1001,1,-1001,4,-1001,6,4,-1001,7,7,0,7,4,8,7,4,2,0,8,2,0,0,8,6,7,7,7,7,5,3,-1001,6,6,5,-1001,-1001,4,9,4,-1001,3,9,-1001,2,7,5,-1001,-1001,1,9,8,0,4,4,5,8,1,4,7,9,2,1,9,9,8,8,5,-1001,5,1,3,9,-1001,2,4,0,3,2,0,3,3,-1001,6,6,-1001,8,-1001,2,5,5,7,5,1,-1001,4,5,0,7,1,9,-1001,3,-1001,2,4,8,1,6,0,9,3,4,9,-1001,4,4,6,2,0,-1001,7,7,0,9,7,-1001,-1001,6,5,8,-1001,3,8,1,0,2,9,0,3,9,3,6,1,3,0,-1001,5,2,9,4,-1001,5,8,6,-1001,-1001,1,8,6,-1001,0,5,0,5,-1001,1,-1001,7,8,3,-1001,1,7,1,4,3,3,9,0,2,3,9,9,6,-1001,2,4,2,2,6,8,7,-1001,8,-1001,9,9,5,7,3,9,-1001,-1001,1,2,4,1,0,9,7,7,9,7,5,4,2,8,1,-1001,4,2,5,8,2,2,9,3,1,2,3,1,0,8,5,6,-1001,2,0,2,9,7,8,4,-1001,6,8,1,6,-1001,6,7,0,0,9,8,8,8,1,-1001,5,5,2,9,4,3,3,1,0,5,1,7,3,3,5,7,1,8,4,2,5,7,2,4,-1001,4,0,7,0,9,6,5,-1001,0,-1001,3,1,4,9,-1001,-1001,4,1,6,2,2,1,5,3,8,7,5,6,6,9,4,6,9,3,1,6,7,-1001,-1001,-1001,-1001,6,-1001,9,3,2,6,3,-1001,8,3,0,-1001,9,6,8,2,2,-1001,4,4,-1001,3,3,2,-1001,3,6,-1001,5,5,4,3,7,1,8,-1001,-1001,2,8,-1001,5,4,3,9,-1001,6,-1001,6,4,4,6,9,7,3,3,1,2,8,7,2,6,8,7,8,7,-1001,4,9,3,-1001,7,5,5,8,4,7,2,7,2,8,3,8,1,2,-1001,5,-1001,1,9,2,9,0,9,9,9,-1001,7,3,8,7,8,1,2,7,4,6,4,3,4,7,9,5,8,0,3,-1001,8,3,3,5,9,-1001,7,1,4,2,6,0,6,6,3,8,5,0,-1001,2,6,-1001,7,-1001,0,-1001,-1001,6,7,-1001,6,4,7,5,5,7,9,4,0,-1001,1,4,0,-1001,5,4,8,7,-1001,2,1,9,0,9,6,5,9,7,8,0,6,0,-1001,0,7,9,9,-1001,-1001,7,5,5,9,4,1,8,3,1,3,3,0,1,4,0,-1001,-1001,1,9,9,1,3,7,-1001,6,1,8,6,-1001,1,2,9,4,3,-1001,6,3,4,6,-1001,9,7,6,7,8,1,6,3,6,8,3,-1001,6,1,7,2,7,1,2,5,2,1,5,2,-1001,5,9,1,2,3,8,6,5,3,7,5,0,-1001,3,1,-1001,2,-1001,2,-1001,7,7,5,6,-1001,1,5,4,2,-1001,-1001,-1001,1,9,6,0,-1001,7,3,1,7,8,1,8,0,8,3,-1001,1,3,8,2,2,4,4,9,-1001,5,9,0,6,4,-1001,3,0,7,6,2,-1001,0,1,4,7,7,3,6,-1001,1,4,-1001,7,9,4,-1001,6,1,2,1,8,8,8,1,0,7,2,-1001,9,5,1,7,0,9,2,0,-1001,1,-1001,1,-1001,3,8,8,5,-1001,-1001,-1001,0,6,1,1,9,8,2,1,-1001,6,8,0,0,-1001,7,0,9,5,2,7,5,-1001,2,-1001,8,8,7,7,9,-1001,9,8,5,6,9,9,7,9,-1001,-1001,1,-1001,6,6,-1001,2,3,6,7,2,-1001,1,1,7,4,-1001,6,1,2,-1001,6,8,6,-1001,3,3,3,0,-1001,7,4,5,7,8,3,6,5,9,5,9,7,0,3,5,5,2,6,-1001,9,8,2,5,9,5,3,5,9,0,4,2,5,8,2,9,-1001,-1001,5,3,0,7,4,7,7,-1001,6,4,9,0,0,0,6,4,1,-1001,5,8,4,4,8,-1001,7,-1001,4,3,1,1,9,-1001,1,1,1,7,-1001,4,-1001,0,-1001,4,6,9,7,5,7,-1001,-1001,5,6,6,6,3,-1001,6,2,8,9,6,2,8,0,9,-1001,5,3,8,8,-1001,5,9,5,1,3,4,-1001,-1001,3,5,-1001,9,2,0,9,3,-1001,3,-1001,1,8,5,8,7,6,5,-1001,6,1,5,3,-1001,7,5,-1001,8,3,0,3,9,9,-1001,-1001,9,4,-1001,9,0,-1001,7,0,8,5,7,5,-1001,5,-1001,5,8,-1001,0,-1001,-1001,2,2,8,5,6,3,2,8,9,7,0,2,2,-1001,1,6,8,8,0,-1001,1,6,8,5,2,0,8,7,5,-1001,7,1,8,9,4,8,3,8,3,4,-1001,4,2,1,8,5,3,0,9,1,-1001,-1001,2,6,3,8,-1001,1,0,1,8,0,2,3,1,-1001,-1001,-1001,8,0,2,6,0,-1001,4,6,9,7,9,2,-1001,-1001,-1001,9,2,7,5,8,-1001,6,3,9,9,5,6,5,0,6,1,6,6,7,7,9,7,9,7,2,0,5,1,7,8,1,9,5,5,9,7,1,4,3,6,0,9,4,1,6,5,2,8,8,2,6,6,1,-1001,7,0,5,7,1,9,3,4,9,9,6,3,5,-1001,7,6,0,3,1,1,8,8,8,6,6,1,8,9,1,3,1,8,5,3,7,1,3,8,8,7,6,3,-1001,-1001,2,4,-1001,4,0,2,9,0,7,8,5,8,7,6,3,6,4,-1001,5,4,0,-1001,5,8,8,3,9,-1001,9,2,1,3,9,2,5,9,3,8,-1001,1,6,9,-1001,1,4,2,6,1,7,-1001,7,1,-1001,2,7,4,7,6,0,6,-1001,2,8,6,-1001,-1001,2,2,5,3,8,-1001,7,7,2,1,6,-1001,7,5,-1001,0,6,7,8,-1001,7,7,8,-1001,2,7,9,-1001,9,1,2,8,3,0,4,8,-1001,4,3,9,1,-1001,9,5,8,5,-1001,0,9,9,0,5,7,3,-1001,2,8,3,-1001,7,1,-1001,7,9,8,8,9,2,6,8,3,0,6,6,2,3,5,5,1,3,0,0,2,2,4,5,4,-1001,0,-1001,0,2,-1001,9,-1001,4,7,3,9,7,8,-1001,8,9,1,2,8,6,5,2,7,6,0,-1001,-1001,7,-1001,5,-1001,8,2,9,5,3,5,7,4,6,3,4,-1001,3,9,5,-1001,-1001,4,6,0,4,2,3,7,2,4,2,3,8,6,9,2,0,3,0,3,-1001,1,9,0,-1001,7,2,6,7,1,-1001,3,3,8,9,6,-1001,3,2,-1001,3,1,0,-1001,-1001,2,-1001,1,0,-1001,1,0,-1001,0,5,7,1,9,9,2,5,9,7,-1001,2,8,3,0,0,8,9,1,9,1,4,8,-1001,5,2,4,6,9,0,7,-1001,2,1,7,-1001,-1001,4,9,0,0,-1001,2,6,5,4,8,-1001,9,-1001,8,1,1,0,0,2,7,3,-1001,7,-1001,2,4,6,8,0,4,8,2,6,4,8,-1001,3,7,4,6,7,-1001,3,2,-1001,8,5,5,4,-1001,8,4,5,7,2,1,4,8,0,3,5,0,7,0,-1001,8,-1001,0,5,2,-1001,8,5,4,-1001,3,6,9,-1001,8,8,4,0,1,1,6,2,2,5,-1001,3,8,-1001,2,-1001,0,-1001,5,6,9,5,9,-1001,8,9,7,5,2,8,2,3,6,6,-1001,6,0,3,7,9,2,6,4,0,2,0,4,-1001,9,7,6,4,-1001,7,8,-1001,3,2,8,9,1,-1001,4,3,8,8,4,0,7,-1001,1,5,7,4,6,-1001,6,3,1,1,6,-1001,8,1,7,8,2,4,5,6,6,6,-1001,3,-1001,3,8,1,9,-1001,0,5,0,5,3,8,5,0,7,9,5,0,3,7,1,6,6,4,3,5,5,9,-1001,1,0,9,6,3,9,3,-1001,2,8,2,7,5,3,7,-1001,7,2,0,1,7,6,9,8,0,-1001,6,-1001,3,-1001,3,0,1,4,7,3,0,-1001,0,0,8,0,0,9,3,0,4,5,0,6,0,0,0,4,4,6,1,8,4,8,7,5,8,5,6,2,-1001,4,0,0,7,7,-1001,3,9,8,3,9,3,5,1,9,7,8,8,5,7,4,-1001,4,5,6,0,6,1,9,1,6,0,5,2,4,2,-1001,2,5,3,3,4,7,3,7,7,0,0,8,6,3,6,-1001,-1001,9,2,7,2,4,7,8,1,-1001,2,8,4,4,9,1,9,8,-1001,7,2,4,0,0,1,1,-1001,4,8,9,-1001,5,2,-1001,5,2,9,1,7,8,5,7,3,1,-1001,5,7,2,0,3,2,7,6,8,5,-1001,4,2,4,-1001,0,9,-1001,3,5,3,7,4,-1001,9,-1001,1,9,-1001,8,3,7,5,1,3,2,6,3,-1001,8,6,9,8,-1001,7,1,8,7,7,4,5,4,9,-1001,4,5,3,0,4,9,-1001,5,5,5,0,9,-1001,5,6,8,6,2,2,-1001,9,0,6,2,4,2,0,7,6,1,9,-1001,-1001,8,6,2,8,7,3,-1001,4,4,7,9,7,6,6,-1001,7,3,5,8,-1001,-1001,7,7,-1001,8,-1001,9,0,8,6,0,1,3,8,2,6,4,5,7,6,5,3,4,8,8,7,2,-1001,6,1,4,0,2,6,1,9,7,2,4,0,8,7,4,7,3,4,6,3,9,4,4,1,4,6,6,5,7,7,-1001,3,7,-1001,4,5,1,1,9,6,8,1,6,1,2,6,7,9,3,-1001,0,8,6,-1001,-1001,6,4,2,2,3,9,6,1,3,-1001,2,0,-1001,2,6,-1001,5,9,9,-1001,1,7,0,4,7,-1001,2,-1001,0,5,7,8,0,9,7,-1001,8,7,8,3,1,4,3,-1001,4,7,1,8,4,8,2,3,2,3,2,3,3,8,9,7,3,5,7,7,3,-1001,3,4,5,2,0,4,-1001,5,4,8,4,8,0,9,-1001,1,9,3,3,-1001,3,-1001,-1001,9,-1001,6,1,7,3,4,-1001,0,2,6,7,3,8,-1001,1,-1001,5,8,9,-1001,5,0,4,5,4,1,8,1,2,6,2,0,4,9,6,0,2,5,8,0,-1001,6,-1001,3,5,1,6,3,9,7,8,8,4,4,-1001,0,0,0,7,5,-1001,-1001,6,3,5,4,5,6,4,7,-1001,4,1,7,3,9,-1001,-1001,5,0,-1001,9,4,-1001,4,5,6,6,6,2,-1001,7,6,3,1,3,-1001,0,5,9,6,-1001,7,3,2,3,1,6,6,-1001,3,4,1,7,4,7,2,2,0,6,1,2,2,3,4,6,8,-1001,2,2,3,-1001,-1001,6,3,7,3,9,-1001,8,3,4,1,0,0,5,4,9,8,5,5,8,9,0,2,2,3,7,0,3,7,8,0,8,4,2,-1001,8,6,-1001,-1001,0,3,5,6,9,9,1,9,-1001,1,1,-1001,9,-1001,0,3,2,-1001,7,7,8,7,4,7,9,6,7,0,8,8,1,-1001,4,2,9,3,-1001,-1001,2,5,7,6,3,7,-1001,3,6,0,2,0,7,7,5,0,0,-1001,1,9,5,2,8,2,5,4,0,1,3,4,0,-1001,-1001,2,4,2,2,-1001,5,9,2,3,9,8,-1001,9,-1001,4,-1001,4,2,4,3,1,6,6,1,0,-1001,6,1,2,-1001,2,5,2,3,5,2,-1001,-1001,3,-1001,4,8,3,-1001,8,6,1,0,0,5,3,3,-1001,-1001,6,3,9,6,8,1,3,6,5,-1001,3,4,5,8,1,5,9,7,7,4,3,-1001,2,-1001,-1001,4,3,0,9,1,4,3,2,1,2,2,5,5,1,5,8,3,7,3,-1001,7,2,-1001,7,0,9,7,5,1,9,5,4,7,-1001,5,5,3,3,-1001,2,6,-1001,5,0,9,7,4,6,0,4,3,3,-1001,5,8,1,9,9,4,6,9,5,9,-1001,9,4,8,9,-1001,-1001,2,8,6,0,-1001,3,-1001,0,2,5,-1001,2,5,8,5,-1001,-1001,0,0,8,-1001,9,9,0,0,9,-1001,5,4,0,2,3,1,9,2,2,5,1,6,3,1,5,-1001,8,9,4,0,5,-1001,3,4,1,2,0,-1001,5,4,8,1,5,-1001,-1001,7,9,3,6,6,0,9,5,2,6,2,-1001,2,1,7,-1001,1,6,4,0,0,0,4,0,8,4,9,8,9,-1001,2,6,6,7,4,1,3,4,-1001,9,6,9,7,-1001,0,2,5,0,1,3,4,1,1,8,3,1,9,6,6,-1001,8,6,0,5,5,2,8,9,-1001,0,8,3,5,8,7,-1001,7,-1001,-1001,7,5,2,5,-1001,0,3,-1001,2,2,1,-1001,3,2,2,9,3,6,-1001,0,6,0,-1001,-1001,2,0,9,3,-1001,3,4,-1001,7,7,8,-1001,6,0,6,6,-1001,8,0,-1001,0,3,1,3,7,0,5,0,0,6,-1001,2,3,8,0,0,7,2,2,7,7,5,0,1,-1001,3,4,3,4,1,3,4,2,-1001,8,-1001,7,4,3,6,9,4,1,0,0,5,2,-1001,8,8,9,8,3,-1001,7,0,2,2,5,1,4,9,-1001,6,2,5,6,0,2,7,9,9,1,-1001,5,3,-1001,7,7,6,4,1,3,7,1,6,0,7,9,3,8,3,-1001,7,2,5,6,1,0,4,5,6,-1001,9,0,3,0,-1001,-1001,-1001,1,-1001,5,0,6,1,5,6,1,3,0,4,1,2,5,6,-1001,1,2,6,4,-1001,-1001,3,4,5,7,3,-1001,4,3,-1001,2,0,4,7,6,2,0,3,-1001,8,8,2,9,4,7,5,8,0,3,-1001,-1001,6,1,6,-1001,3,2,1,-1001,3,3,9,3,9,-1001,7,9,6,8,7,1,6,-1001,3,8,3,0,2,4,5,2,0,5,9,5,9,0,7,2,7,5,5,5,7,4,8,6,1,6,-1001,-1001,7,-1001,2,2,6,4,-1001,-1001,4,7,-1001,7,3,2,3,9,0,4,2,0,9,5,2,2,9,0,-1001,2,2,3,-1001,8,7,-1001,7,8,6,1,7,2,-1001,9,3,1,1,2,-1001,6,7,5,5,8,-1001,0,4,2,0,5,5,0,6,5,9,1,-1001,9,4,1,8,-1001,7,6,6,7,5,1,8,7,9,0,6,1,4,-1001,7,1,5,4,1,4,4,3,-1001,9,8,9,-1001,1,5,3,3,7,-1001,5,4,3,7,8,2,4,8,-1001,4,-1001,-1001,8,-1001,1,-1001,0,3,1,3,4,4,7,9,0,1,5,-1001,9,-1001,6,8,7,-1001,4,-1001,1,-1001,8,6,0,7,4,3,5,9,1,0,8,2,9,7,-1001,1,5,8,5,8,9,5,8,-1001,-1001,4,5,4,0,9,9,0,8,5,2,9,2,0,-1001,4,7,7,8,1,9,6,-1001,3,4,4,1,7,9,8,0,8,-1001,5,3,3,6,5,7,-1001,-1001,0,6,9,1,2,8,6,9,0,5,2,3,8,9,8,0,3,3,0,1,4,-1001,9,0,1,3,6,2,6,0,-1001,0,9,3,9,3,3,3,5,1,-1001,-1001,1,1,7,-1001,-1001,8,3,-1001,-1001,9,5,6,6,7,7,0,2,-1001,6,7,9,4,8,9,2,-1001,4,8,6,4,-1001,5,8,8,3,9,8,7,9,-1001,2,9,2,9,1,1,3,0,6,7,3,4,2,9,-1001,6,-1001,4,-1001,2,8,2,3,4,1,3,0,-1001,4,7,8,4,8,-1001,6,3,3,7,0,-1001,3,9,3,1,1,2,0,2,6,4,8,9,0,8,7,1,1,6,4,0,3,0,2,7,0,-1001,1,-1001,-1001,-1001,9,0,-1001,-1001,7,8,2,-1001,5,5,8,-1001,3,5,2,2,2,5,3,7,7,5,8,8,1,4,-1001,-1001,7,9,7,2,4,7,7,6,8,-1001,1,6,3,2,9,7,1,2,7,0,2,9,9,9,9,8,-1001,7,-1001,4,8,7,0,-1001,9,3,3,-1001,7,1,-1001,-1001,9,5,8,8,4,7,4,9,5,5,1,-1001,0,6,6,8,7,8,-1001,-1001,-1001,3,4,6,5,1,0,-1001,-1001,1,5,1,3,-1001,3,4,6,4,8,2,2,2,-1001,2,5,1,6,-1001,6,5,-1001,1,4,2,2,2,7,8,2,7,4,0,2,3,3,-1001,7,0,-1001,7,9,6,0,-1001,2,8,4,8,5,2,3,6,8,2,2,6,1,8,5,4,6,2,4,0,0,4,9,7,7,-1001,1,1,-1001,6,6,6,4,1,-1001,3,4,-1001,5,0,8,8,1,8,3,2,9,6,2,6,9,5,9,8,5,1,0,7,7,-1001,8,9,0,8,8,-1001,6,3,6,6,9,8,1,4,1,5,5,0,7,7,0,9,9,1,5,3,5,6,-1001,-1001,-1001,4,-1001,0,4,-1001,2,6,5,1,4,6,1,5,4,6,7,4,2,6,7,0,4,3,-1001,8,4,8,7,9,4,0,5,6,3,7,1,9,3,-1001,7,3,4,9,0,0,3,2,0,6,6,0,6,5,0,8,3,1,2,4,8,3,6,-1001,3,1,7,3,7,0,7,2,2,5,2,8,8,5,8,9,3,7,9,9,8,6,6,5,8,-1001,8,-1001,5,7,1,0,4,9,5,2,8,-1001,1,0,4,7,2,3,2,2,5,0,4,5,0,3,-1001,7,0,7,2,3,-1001,-1001,1,5,0,5,5,8,4,4,2,7,2,1,0,5,8,2,5,4,-1001,3,5,2,7,0,0,0,8,2,5,6,0,4,0,3,8,4,-1001,1,2,8,-1001,4,2,8,3,2,1,2,4,6,-1001,4,4,-1001,1,4,5,0,9,2,3,-1001,-1001,3,2,3,3,0,8,3,3,3,3,1,6,2,3,4,4,2,3,-1001,6,7,3,9,9,5,1,0,2,3,4,8,5,1,5,3,0,-1001,4,3,7,-1001,0,1,7,-1001,4,5,-1001,9,5,9,-1001,3,5,5,7,7,8,0,0,8,7,9,9,9,4,9,5,3,-1001,5,7,4,-1001,1,-1001,7,-1001,1,-1001,3,6,9,-1001,4,4,1,-1001,2,0,6,9,2,9,1,8,3,9,0,2,6,8,1,-1001,6,4,4,2,5,0,1,0,9,4,6,4,8,8,-1001,1,-1001,3,5,0,0,4,0,5,5,4,5,4,0,8,9,4,2,3,1,-1001,-1001,-1001,3,4,1,0,2,2,1,-1001,-1001,0,6,0,2,5,2,-1001,2,3,4,0,-1001,1,0,9,2,2,6,8,-1001,8,-1001,6,9,2,-1001,2,9,5,3,-1001,8,2,9,7,6,-1001,2,3,9,-1001,6,9,7,3,7,-1001,6,5,9,8,5,5,4,7,5,2,-1001,4,3,8,8,8,7,9,4,5,6,1,0,-1001,9,1,5,2,0,-1001,9,2,3,5,1,5,1,1,7,3,0,0,9,7,9,0,8,6,9,2,7,0,-1001,2,8,8,9,3,4,8,9,2,9,7,-1001,-1001,2,2,-1001,4,7,3,8,3,3,5,-1001,5,3,9,2,7,3,3,7,-1001,-1001,3,9,1,3,-1001,8,1,4,0,7,6,-1001,4,8,8,4,7,-1001,3,6,9,4,9,7,9,8,-1001,-1001,2,1,8,3,8,2,0,0,9,5,2,-1001,9,5,7,1,-1001,3,8,-1001,5,6,5,2,1,4,2,9,9,2,8,5,7,6,0,4,0,3,6,2 };
    root = CreateBinaryTree(num, -1001);
    ser = serialize(root);
    deser = deserialize(ser);

    num = { 6,9,2,6,8,8,6,7,9,9,2,4,0,0,7,8,4,4,3,4,8,5,1,3,2,8,4,6,0,2,0,8,5,0,9,9,3,8,9,7,7,4,2,2,0,1,8,7,2,9,6,7,8,3,7,5,7,1,9,3,4,0,6,1,1,5,0,3,0,5,8,3,8,3,1,7,8,8,0,1,4,2,1,1,7,7,3,7,2,3,5,8,8,8,5,7,9,4,6,9,2,6,5,1,6,6,4,8,1,5,0,9,9,2,1,4,3,4,2,2,2,5,8,1,1,2,0,7,9,9,7,2,9,2,8,0,4,8,5,7,7,4,8,2,1,2,2,6,3,7,0,1,4,7,9,7,6,8,3,5,3,2,0,1,6,7,2,5,2,9,5,0,8,5,7,6,7,1,7,9,0,3,5,9,3,1,9,1,0,3,1,6,1,5,2,0,4,8,6,3,4,9,4,8,4,4,1,0,5,3,3,9,1,6,4,3,8,6,8,9,1,9,9,8,1,5,6,0,9,9,7,3,9,6,7,0,5,2,0,6,9,6,7,1,1,9,3,1,5,6,0,4,3,3,9,0,4,4,5,0,6,2,5,9,7,5,1,7,3,3,0,6,4,1,7,2,9,3,3,6,3,8,6,0,6,4,3,7,3,1,2,8,5,3,4,8,1,8,3,8,1,0,2,8,4,5,9,1,4,2,0,3,9,1,1,5,4,7,5,6,0,4,3,5,7,3,6,5,6,4,9,6,4,4,5,4,8,8,8,6,2,2,2,8,5,2,2,6,1,9,0,9,1,4,8,4,2,4,5,1,8,6,7,0,5,9,2,7,2,2,3,6,9,7,6,0,6,0,7,8,8,9,5,5,5,2,1,2,2,6,2,9,6,5,2,8,7,3,6,0,4,4,3,3,6,4,0,9,4,2,1,5,7,7,3,9,7,3,2,6,5,0,9,5,8,2,2,3,2,4,7,0,5,1,5,1,1,3,0,7,9,9,5,9,8,5,5,9,4,2,9,4,2,1,8,1,4,7,8,5,7,3,8,8,0,6,0,0,0,3,1,3,1,2,0,4,3,3,0,2,3,9,7,7,7,5,7,7,6,2,1,1,5,8,0,4,9,6,4,1,8,4,6,2,7,2,5,7,3,6,0,6,4,3,5,8,1,7,1,1,3,6,3,0,6,3,9,4,7,4,7,8,4,3,0,7,4,1,8,8,5,9,0,4,7,9,8,3,3,9,5,4,1,3,9,8,8,0,4,0,0,9,6,2,3,5,5,8,5,7,9,4,7,2,8,3,3,6,2,0,5,5,9,6,9,4,5,6,6,3,7,1,4,7,2,1,8,3,0,5,8,1,4,6,9,2,3,5,2,6,1,2,8,9,9,8,5,9,5,2,9,4,4,1,5,9,6,9,5,5,5,3,1,1,5,8,2,9,7,1,7,0,0,9,1,8,9,2,3,0,5,1,2,0,8,4,8,9,3,4,4,8,4,1,7,0,4,7,0,7,2,1,8,6,8,8,7,3,6,0,9,5,5,0,4,8,4,1,9,0,6,9,0,0,3,2,2,2,3,9,9,9,7,8,5,5,0,1,2,9,5,2,4,2,9,3,4,5,6,5,0,2,5,9,4,9,0,6,9,3,5,4,3,3,4,7,8,6,9,1,9,7,3,5,2,2,7,9,3,8,0,4,2,0,1,2,2,4,2,8,7,1,2,1,9,8,5,4,9,7,6,0,4,4,4,6,7,7,1,3,9,5,1,8,7,1,6,4,3,7,7,2,5,6,4,4,1,1,2,9,8,5,3,2,0,6,8,4,6,5,6,5,7,7,9,1,9,9,6,2,4,2,3,0,5,2,9,7,8,3,8,6,0,4,8,7,2,2,2,4,2,0,6,3,7,7,3,3,8,9,7,8,1,0,4,5,1,6,9,5,2,9,8,3,4,7,3,7,6,9,5,7,6,4,3,3,2,9,0,9,8,9,3,3,7,5,0,9,5,2,4,5,6,6,5,1,9,1,5,1,3,5,6,2,4,2,0,4,5,3,1,6,3,5,1,5,5,7,5,7,8,4,1,4,1,5,0,9,6,6,2,4,4,2,5,4,9,7,4,1,1,5,1,9,9,0,1,6,6,0,0,6,8,4,3,2,9,4,6,1,3,4,0,9,7,1,4,6,8,1,2,3,6,2,7,8,9,6,1,2,4,8,9,5,7,2,6,3,9,4,2,9,7,2,5,0,0,2,5,0,3,6,1,1,7,0,7,6,0,2,3,6,0,6,3,8,6,1,9,6,8,2,9,8,8,2,7,6,4,2,3,3,8,8,4,7,9,2,7,3,6,6,8,6,2,1,0,4,4,7,0,2,9,7,5,0,3,5,8,4,3,9,2,4,5,0,2,5,6,9,5,4,9,4,3,9,2,7,5,5,1,6,5,5,7,1,1,6,2,0,2,2,9,7,8,6,5,8,4,5,3,9,0,9,9,5,4,0,4,9,5,6,1,4,2,4,6,0,1,8,9,1,4,4,4,4,1,6,7,6,6,6,5,2,6,3,6,5,4,6,0,4,1,0,7,8,5,3,9,2,5,5,3,7,5,9,2,6,5,1,9,5,4,8,2,1,2,1,6,1,0,0,8,8,5,3,8,7,4,8,6,3,5,1,3,4,4,9,0,9,3,3,1,7,5,9,4,9,0,2,1,5,5,6,6,8,4,7,2,5,4,4,8,4,1,6,1,4,1,2,0,5,2,3,0,9,4,6,2,5,3,9,3,3,6,2,1,5,3,9,0,1,2,0,7,5,3,7,7,0,9,5,6,7,0,6,3,0,7,5,2,9,5,8,7,8,0,9,5,2,6,0,4,4,7,9,9,2,0,7,0,0,7,6,7,7,7,9,6,6,5,5,8,0,2,5,7,4,6,7,5,2,0,7,7,4,2,7,0,3,3,8,6,5,8,2,3,9,2,9,9,7,6,7,0,5,0,8,2,1,9,3,2,3,0,5,6,7,8,7,7,4,9,0,9,4,6,2,8,6,0,1,2,1,9,3,9,8,6,4,5,2,1,3,2,4,8,6,8,1,4,0,9,0,8,3,9,6,7,1,1,6,2,2,8,4,9,0,4,1,7,6,9,7,7,0,1,0,3,8,1,7,7,0,0,4,8,3,7,5,6,7,0,5,8,7,3,3,9,0,0,8,4,2,3,0,5,4,1,6,8,8,5,9,2,7,7,0,6,4,5,6,7,0,5,9,5,8,0,5,1,8,3,7,4,5,9,4,6,2,7,1,3,2,0,0,2,1,4,9,9,1,4,6,3,3,1,0,4,6,9,3,3,9,5,6,1,2,5,0,4,1,2,1,7,8,2,4,9,9,6,4,1,7,2,1,4,6,5,2,2,2,8,5,9,2,6,0,3,8,6,2,4,4,6,2,1,3,2,4,7,1,3,4,5,6,2,4,0,0,7,2,4,7,5,2,6,3,5,3,4,1,5,3,3,2,0,8,2,3,7,1,9,0,2,5,0,7,7,4,3,7,2,4,6,8,2,0,5,1,4,4,4,2,5,4,5,6,5,9,8,4,6,1,7,1,3,3,4,5,2,7,9,7,6,4,9,9,7,9,9,9,7,2,8,4,3,5,1,1,0,4,2,1,7,7,2,0,8,9,1,6,0,0,4,4,7,2,9,2,0,8,6,9,8,6,5,4,4,5,0,8,4,3,8,9,7,2,9,7,6,6,3,1,1,0,7,0,4,6,4,3,4,7,6,5,1,5,7,0,2,0,2,6,4,2,9,2,5,3,1,4,6,8,7,8,8,3,7,7,8,9,7,5,4,7,1,9,9,3,9,8,2,2,9,4,5,9,0,7,2,3,1,9,7,5,4,6,3,5,1,2,5,2,7,6,0,9,7,0,3,2,9,0,9,1,0,2,1,5,9,6,7,4,0,1,6,8,9,3,1,4,1,6,6,1,0,7,5,7,2,7,2,6,2,6,6,0,6,8,6,6,8,3,8,5,4,8,4,5,3,9,1,7,0,6,6,3,4,2,0,3,2,5,5,7,0,4,4,7,0,6,2,0,3,6,3,4,7,8,6,6,7,3,4,2,9,7,6,9,7,5,9,5,3,6,9,7,7,6,9,7,5,2,9,2,7,0,5,3,9,2,9,1,1,1,6,9,7,8,6,9,1,4,4,3,9,2,6,5,9,1,2,9,7,2,5,0,1,3,3,2,8,8,3,4,4,3,4,3,4,2,0,5,7,1,8,7,9,9,7,6,7,6,7,3,4,0,1,3,9,7,0,3,7,9,2,5,2,6,6,3,2,7,3,9,4,2,0,8,7,5,3,2,3,7,0,6,1,6,2,2,1,9,4,1,3,7,7,9,0,5,0,9,6,6,4,2,8,8,1,6,5,5,6,6,1,1,5,6,2,4,6,5,2,6,7,3,3,9,0,3,9,9,1,8,5,1,4,5,3,5,9,2,8,6,8,8,7,1,1,5,8,4,1,8,2,5,0,9,0,8,7,3,8,2,1,8,4,5,7,3,6,7,7,2,2,0,8,2,0,0,7,9,7,0,8,4,5,1,3,8,3,5,6,7,2,5,2,7,5,1,3,5,9,0,6,3,1,8,2,1,2,6,8,8,7,2,5,4,8,9,7,8,9,1,2,6,0,8,1,8,7,7,5,5,4,8,3,8,6,4,4,9,9,2,8,5,3,1,3,3,0,8,4,5,8,4,8,8,3,2,7,1,1,6,9,6,7,2,1,8,0,6,5,2,2,1,2,8,7,7,4,1,2,0,1,0,4,9,5,1,8,2,8,1,0,4,5,7,9,2,7,9,2,4,9,9,4,8,1,5,4,3,9,9,5,8,2,8,7,8,9,0,0,4,9,6,3,6,5,0,4,8,1,6,3,5,7,6,0,7,8,4,8,4,6,8,1,0,3,5,8,6,1,0,3,8,3,1,6,6,8,9,4,4,0,6,4,4,1,2,4,3,1,0,4,0,5,3,2,9,0,6,3,3,6,1,3,7,3,8,8,3,6,9,7,2,5,5,2,3,5,5,7,1,4,0,1,7,8,7,1,4,4,3,2,3,6,3,9,3,4,0,6,0,2,7,1,9,8,9,0,3,4,8,1,2,8,4,0,9,5,5,9,0,5,3,0,9,9,7,9,5,7,0,5,2,7,0,7,7,3,6,3,5,8,0,7,8,4,3,1,9,5,9,0,8,6,5,0,9,4,8,4,1,1,2,0,8,2,9,8,8,9,4,1,2,2,1,0,0,6,8,8,1,6,1,7,2,1,7,9,4,4,0,9,4,3,1,1,2,5,5,8,4,8,4,4,7,4,2,5,9,4,8,4,9,4,3,7,2,2,5,2,4,5,9,7,3,7,8,4,2,4,9,3,0,1,0,3,8,3,7,3,9,2,1,9,1,0,9,0,2,5,2,4,2,7,0,9,1,4,2,2,3,9,0,2,8,1,6,1,8,9,9,1,8,3,3,7,9,0,8,8,8,7,7,8,2,5,8,5,7,1,5,2,6,0,8,1,7,8,0,0,2,2,3,7,3,9,5,7,0,2,1,3,4,6,2,2,8,6,5,2,2,2,1,8,4,5,5,7,3,8,0,5,3,4,8,4,0,2,0,5,4,4,9,2,1,4,1,4,8,6,3,7,5,8,5,5,5,3,9,5,2,6,5,0,2,8,0,3,4,8,7,6,9,3,5,2,7,7,2,2,3,0,9,1,3,2,6,6,1,1,1,2,4,6,4,9,3,2,9,3,0,1,1,8,5,0,6,1,6,4,6,3,6,0,4,3,9,4,8,2,3,4,2,6,1,3,6,9,6,8,6,4,8,6,3,9,4,8,0,5,2,2,5,0,1,4,6,4,8,4,9,6,5,2,1,3,8,0,8,6,9,0,2,0,4,9,6,4,6,1,0,7,5,0,2,4,0,3,3,1,1,0,5,9,6,1,0,1,5,3,5,3,9,2,9,2,6,1,1,6,1,8,2,9,3,6,7,5,8,3,7,8,7,0,8,6,2,7,7,2,3,3,8,5,5,2,4,2,5,5,6,0,5,3,2,8,4,1,3,9,9,9,3,6,3,4,8,0,3,4,1,5,2,8,3,5,3,9,2,6,1,9,9,5,9,6,8,9,9,6,8,2,3,7,8,1,8,5,5,0,4,8,3,5,9,4,4,7,0,2,6,5,3,5,5,4,9,0,8,9,7,0,1,1,6,7,0,2,6,5,2,8,7,1,2,3,4,7,4,8,0,6,1,5,7,5,9,5,9,2,5,5,7,4,4,2,4,2,0,9,5,5,3,7,0,4,9,4,3,8,7,3,1,1,0,2,9,9,3,2,3,1,5,1,8,2,8,0,5,4,4,8,9,0,8,4,3,0,7,3,0,9,2,7,7,5,5,0,2,0,6,9,4,7,9,9,6,0,0,7,9,0,4,6,4,9,6,3,2,8,6,0,9,0,8,8,4,3,7,4,9,3,3,7,1,5,4,1,5,2,8,2,3,4,5,9,9,7,4,8,9,4,3,8,8,5,4,5,3,4,4,2,7,7,2,5,2,3,9,5,9,4,0,9,2,8,1,5,6,9,9,6,9,8,0,8,7,8,4,5,5,8,6,9,0,4,4,3,2,2,9,4,3,8,8,8,5,9,0,8,1,5,0,4,8,6,3,9,6,4,9,0,1,4,9,1,1,5,0,6,8,5,4,6,5,8,1,1,5,7,8,1,8,4,8,9,6,5,5,9,6,1,6,8,5,3,8,9,1,6,5,2,9,5,8,5,0,9,3,5,9,7,2,9,8,6,5,2,5,0,3,3,4,6,5,3,0,4,3,8,8,8,4,8,0,6,4,9,7,4,7,3,0,2,0,2,4,8,9,6,4,3,7,9,0,3,0,9,8,7,4,2,3,9,7,3,8,6,4,2,2,7,5,4,7,9,6,9,4,7,1,1,7,4,8,9,9,0,6,1,3,0,6,5,0,2,0,3,3,6,5,5,8,8,0,2,5,5,8,0,5,4,2,2,8,9,4,7,4,5,7,3,8,4,3,0,6,1,3,0,6,0,2,8,0,2,3,7,8,5,2,4,7,0,6,3,4,1,3,1,3,0,9,0,3,6,8,5,7,9,8,5,2,8,0,0,5,1,8,3,1,9,5,0,0,6,3,5,4,3,0,6,9,5,6,6,7,9,4,5,4,1,8,2,6,9,4,8,6,7,6,6,5,4,7,6,0,1,6,2,9,0,4,3,6,3,9,7,4,9,2,9,3,5,7,0,7,0,1,2,8,2,1,8,9,9,8,6,5,4,7,0,5,7,5,5,4,7,6,3,5,9,5,1,4,8,5,5,6,1,0,1,4,8,1,4,3,4,1,3,5,3,6,5,9,8,4,5,4,8,8,9,6,1,6,8,6,8,3,1,0,0,3,1,1,9,2,3,4,6,0,2,3,6,4,9,3,8,6,9,5,6,1,5,4,7,4,9,0,1,7,2,1,6,2,5,1,7,4,5,6,4,6,7,4,3,5,3,2,2,8,9,9,7,5,8,5,0,0,7,2,1,6,2,8,9,0,8,3,0,8,4,6,6,5,3,7,7,0,7,0,7,0,9,6,7,1,0,2,2,6,7,5,4,7,4,2,1,0,5,2,9,6,0,6,5,3,9,7,4,2,5,7,9,6,1,2,7,5,9,0,6,2,3,3,3,8,3,1,6,3,0,7,8,4,2,4,7,1,9,9,2,5,3,0,6,7,4,0,4,2,2,8,0,7,2,4,8,4,6,4,5,3,5,8,7,7,6,0,6,2,0,0,6,0,2,9,6,8,3,3,5,5,1,7,7,0,3,9,4,1,4,7,7,0,3,5,9,0,8,4,5,1,6,9,0,7,3,6,4,7,9,5,4,4,0,0,5,8,3,9,9,2,6,4,3,0,7,5,5,0,4,2,6,7,1,4,9,0,1,2,9,1,6,8,1,9,4,8,4,4,4,5,9,9,2,3,4,5,7,9,8,8,2,5,2,5,7,4,6,2,7,0,9,0,7,4,2,1,7,1,2,6,0,5,0,8,8,7,1,6,5,5,5,7,3,5,2,5,0,1,5,9,5,4,2,6,1,0,5,1,0,4,9,2,9,1,2,5,5,4,2,4,0,9,6,9,4,2,3,9,4,0,2,3,7,6,3,7,0,7,7,8,4,0,2,7,5,5,6,8,7,8,6,9,6,0,1,9,1,6,0,8,9,7,8,6,6,9,6,7,6,1,6,3,2,6,4,9,4,8,0,0,6,8,3,3,6,7,1,7,9,7,9,1,2,5,5,1,7,3,8,5,6,1,4,2,4,8,4,7,4,6,0,2,4,9,2,3,5,8,4,3,5,5,7,4,3,4,4,9,4,0,6,4,3,3,4,9,6,2,9,2,7,0,4,6,6,1,9,3,1,7,4,4,1,3,4,0,4,5,3,0,6,1,5,3,7,7,8,1,4,6,8,0,9,7,4,2,3,2,5,2,8,6,9,6,4,0,4,6,2,3,5,2,5,4,6,3,7,7,0,1,5,4,3,4,8,4,1,5,8,4,5,3,7,7,0,6,7,2,8,6,9,9,9,2,4,0,1,7,9,1,9,3,5,4,0,2,2,4,7,6,0,1,3,2,8,4,8,0,1,7,1,8,3,9,0,5,6,0,6,1,8,1,6,9,5,2,3,4,9,7,8,2,2,4,8,4,8,7,0,9,3,9,7,7,3,8,1,7,6,4,1,8,3,3,4,8,8,9,6,4,5,5,9,1,0,9,3,1,3,4,3,2,7,7,5,1,3,9,6,9,0,5,5,0,7,7,5,6,6,0,8,6,9,7,9,7,2,6,9,8,5,8,5,9,5,4,0,3,7,5,5,2,7,9,1,5,7,7,9,2,8,2,5,2,0,0,0,6,0,0,8,9,5,5,6,4,4,5,8,7,1,2,8,1,9,6,6,2,9,6,2,5,4,3,7,2,2,7,2,1,8,3,7,9,0,2,9,3,8,3,2,2,4,0,3,3,2,0,1,6,3,7,8,5,1,2,4,9,9,0,3,0,6,2,4,2,9,8,7,8,8,0,9,3,4,1,8,8,8,8,3,8,6,3,4,3,7,0,7,7,1,0,1,2,4,8,0,2,7,4,1,2,0,3,6,8,3,5,3,1,6,7,1,8,7,3,8,8,0,4,6,8,9,2,7,1,6,4,8,0,6,2,4,5,9,9,6,3,1,1,6,3,3,0,4,7,1,5,5,6,8,6,9,1,1,8,7,8,1,6,2,6,4,6,3,0,9,8,1,7,8,6,9,9,7,8,3,6,9,5,5,1,7,4,8,6,8,6,4,0,9,0,4,1,0,0,2,9,2,0,3,7,9,7,8,3,6,5,1,7,1,1,0,8,0,7,9,7,6,8,4,5,9,5,2,0,3,5,1,3,0,3,1,2,7,5,2,8,1,6,8,5,4,5,2,0,8,2,7,6,0,7,3,2,2,0,9,1,9,5,7,9,0,4,6,5,0,5,4,2,3,8,5,9,3,9,0,1,2,3,9,9,7,0,8,1,2,0,7,7,0,1,3,0,2,4,1,8,0,2,1,9,9,6,3,4,0,2,1,6,3,5,7,9,2,2,2,0,4,4,0,2,7,8,6,5,0,2,5,2,6,9,2,7,5,6,0,9,2,4,4,6,5,3,2,3,8,4,8,9,8,9,2,6,4,0,4,8,8,7,5,0,5,2,5,2,4,4,3,8,2,6,9,2,3,8,2,4,4,1,0,8,5,6,4,2,5,4,4,6,2,8,2,1,1,5,0,9,3,3,3,0,2,1,1,4,3,0,0,8,2,9,4,8,7,0,3,2,8,3,8,1,4,9,8,2,9,3,5,6,2,1,2,9,2,9,4,5,7,5,8,4,7,8,7,7,9,9,2,5,3,5,7,6,2,5,8,5,7,5,3,9,9,1,1,1,2,7,1,0,8,2,0,8,0,8,1,1,6,2,3,5,4,6,8,4,6,3,9,9,2,3,8,6,5,7,9,8,9,4,6,5,5,0,6,3,2,6,6,2,5,6,9,3,7,3,1,9,4,4,7,1,0,1,4,2,5,3,3,2,7,3,1,4,1,3,5,9,8,7,2,9,0,3,5,2,4,4,2,6,9,0,4,9,1,9,3,0,7,5,4,3,4,1,0,9,1,3,8,0,8,2,7,1,6,5,2,9,8,4,1,2,5,7,4,7,0,6,5,2,1,3,2,4,9,1,8,8,4,7,9,0,3,6,7,9,8,7,4,7,9,7,8,5,9,5,7,6,0,1,7,6,2,9,2,3,5,5,5,2,3,8,1,1,3,0,2,5,5,6,1,1,7,1,6,1,0,6,5,3,8,0,9,9,2,5,2,6,4,5,4,5,8,2,1,2,7,6,3,0,1,9,0,0,9,7,0,9,8,6,1,7,1,5,8,7,2,2,2,1,4,5,2,2,3,7,1,5,7,9,6,6,9,6,4,3,8,0,1,2,8,3,7,1,6,4,4,8,6,9,8,9,1,8,7,5,9,0,7,7,2,4,0,2,1,1,3,8,9,0,7,6,7,5,5,0,7,4,7,0,0,1,7,1,8,2,0,5,1,0,0,5,1,2,2,0,7,8,2,1,0,9,5,3,8,1,4,7,9,8,2,0,0,5,2,9,2,7,7,0,2,1,1,1,0,3,5,1,3,3,5,2,2,4,2,2,9,6,7,9,7,8,1,9,1,7,1,4,7,5,1,1,7,7,1,1,9,1,2,5,8,3,8,4,5,3,4,2,8,6,1,9,6,1,4,7,2,8,9,9,8,5,7,0,8,0,3,0,6,7,3,7,7,8,2,3,1,4,7,9,3,5,2,7,6,3,4,6,1,6,4,7,3,5,2,1,6,6,6,3,7,6,3,0,9,2,6,1,1,0,1,4,6,0,6,4,6,1,8,3,6,9,2,5,5,7,2,0,7,6,8,8,3,1,9,9,3,1,1,9,7,2,1,8,1,0,3,1,1,9,7,8,0,5,2,4,8,0,9,0,8,5,3,8,4,5,4,1,2,9,5,0,7,5,2,4,2,6,0,1,5,5,5,9,0,5,1,9,1,8,8,4,7,0,0,6,2,6,9,5,2,5,6,5,5,3,7,4,7,2,6,4,2,9,9,3,2,8,1,3,4,0,0,8,2,1,5,2,5,7,5,4,8,3,1,4,2,7,8,4,8,3,0,5,3,4,6,1,6,6,2,0,8,2,7,1,8,6,9,6,8,2,6,5,2,2,1,5,2,0,5,3,3,8,7,2,0,5,6,6,2,8,4,4,8,7,5,8,9,9,8,2,6,1,7,3,1,4,7,8,9,2,3,8,3,2,5,2,2,0,4,0,4,0,9,8,0,6,4,1,7,5,1,6,1,3,5,6,4,7,8,8,1,5,3,3,9,6,5,0,4,6,5,1,4,3,5,3,7,6,0,2,5,4,5,0,3,0,6,7,9,4,1,2,2,4,7,2,6,0,5,4,4,1,9,6,6,3,1,9,0,1,9,0,1,5,5,5,5,3,5,6,2,4,2,6,2,7,6,6,3,2,8,3,3,9,9,5,4,3,5,8,0,0,5,0,8,1,1,6,6,7,8,4,5,7,4,0,5,2,0,3,3,5,5,7,5,7,5,9,2,9,7,7,5,9,1,5,5,7,4,2,3,0,9,7,0,1,1,0,6,2,0,2,0,5,9,5,0,2,9,5,8,0,7,1,6,4,0,4,1,3,6,8,6,8,1,1,5,7,3,1,3,7,3,0,0,6,8,9,4,6,4,7,4,0,8,3,8,7,7,4,1,5,0,5,0,0,6,5,6,7,8,6,7,1,1,0,1,2,3,4,0,0,7,2,4,8,1,8,4,1,1,6,6,3,5,8,1,2,2,7,4,5,9,6,9,0,7,9,9,5,9,5,4,5,2,0,4,4,1,7,0,1,2,2,6,1,3,2,4,1,0,5,0,9,7,8,3,1,6,6,8,7,2,3,6,8,1,3,0,5,9,2,9,7,3,9,9,0,0,7,0,0,3,7,4,6,9,9,0,6,6,2,7,0,2,1,5,8,4,1,2,5,1,1,6,2,8,5,4,5,1,4,0,8,9,9,8,3,5,6,8,8,1,1,2,2,6,1,5,4,0,9,2,5,8,2,8,7,0,8,9,0,1,8,7,5,5,1,8,4,9,8,4,4,3,0,9,2,0,7,0,0,8,1,5,8,5,7,4,2,2,0,9,4,9,7,2,0,1,5,3,9,6,3,3,0,9,5,4,3,8,7,6,2,9,8,1,4,1,2,0,0,9,3,8,4,5,5,5,3,6,8,7,3,0,7,9,8,0,4,9,9,2,2,4,7,5,8,6,2,9,2,0,9,8,0,2,2,8,6,3,0,1,6,8,1,5,8,2,6,0,2,5,2,8,4,8,4,0,9,9,2,9,8,3,5,4,0,5,2,1,1,2,3,6,5,4,7,6,5,4,0,1,5,1,6,5,6,0,2,5,0,1,5,2,0,7,0,6,6,1,4,6,0,3,9,0,1,5,5,7,5,5,2,7,0,0,0,7,4,8,0,1,7,4,8,6,8,7,3,7,6,9,1,7,9,5,3,5,9,6,5,6,7,1,3,8,6,0,5,9,7,0,2,0,8,1,7,2,9,1,0,5,4,9,0,6,9,0,2,1,3,6,9,6,5,6,0,9,6,2,7,8,3,6,2,9,4,6,6,8,6,4,3,7,4,8,5,4,7,4,9,4,3,1,3,0,4,5,4,7,6,6,4,7,8,6,5,8,2,4,9,8,8,3,9,4,4,5,1,2,3,0,1,1,1,0,5,8,8,1,9,4,2,7,7,2,0,7,8,6,7,8,2,2,7,3,7,4,5,8,1,3,7,5,8,7,7,1,0,2,0,5,5,9,8,3,1,8,2,2,5,1,5,1,1,8,4,3,8,3,7,8,8,7,8,5,5,9,0,8,6,1,3,8,2,9,2,2,3,1,2,1,0,8,5,1,8,9,8,9,9,3,9,6,1,7,7,3,4,8,2,0,8,4,9,7,2,7,7,1,2,2,2,4,6,5,4,0,7,9,5,2,4,4,3,5,5,4,0,7,7,7,8,4,2,8,3,6,7,7,0,5,5,3,5,1,6,4,0,6,6,9,6,3,2,5,3,9,3,9,1,1,8,4,4,7,1,0,1,7,3,9,2,1,4,6,1,4,5,9,9,2,7,6,6,0,7,1,9,4,2,8,5,3,9,4,7,9,3,3,8,7,9,4,4,3,6,7,9,6,4,5,5,7,8,6,4,4,5,6,6,6,5,4,5,3,5,9,6,0,5,1,1,5,1,6,2,6,6,3,5,9,2,5,8,4,2,3,4,2,8,7,2,3,6,6,3,8,1,6,9,6,7,0,6,8,2,4,0,4,3,0,3,6,7,1,5,7,1,7,9,6,7,8,8,0,7,5,5,4,8,5,0,1,6,9,9,4,9,7,8,2,9,6,1,4,3,6,1,3,2,4,6,8,3,1,8,5,9,6,8,5,2,1,9,7,0,0,5,7,7,2,4,9,1,2,0,0,9,5,9,5,9,1,9,5,7,3,0,7,7,4,6,9,2,4,0,6,9,0,9,4,3,2,1,7,0,8,9,5,0,8,5,9,6,6,8,6,5,9,0,8,6,8,7,7,7,6,6,7,0,2,6,1,6,1,7,3,2,6,5,9,7,6,4,2,8,9,1,7,0,3,0,3,7,7,2,3,9,9,9,5,4,1,5,2,5,4,4,7,2,1,3,5,6,6,5,2,3,5,0,9,5,8,6,9,5,5,3,1,6,7,3,3,3,1,9,2,8,1,7,2,8,3,4,0,5,3,9,3,3,7,5,7,6,7,1,2,0,4,0,4,8,0,5,6,4,2,8,3,8,7,8,2,4,2,7,5,2,2,6,7,9,5,4,0,2,3,8,1,0,7,1,3,9,9,7,1,0,7,3,7,8,4,6,9,6,5,0,1,3,7,8,9,5,6,1,1,8,6,4,6,0,5,2,3,2,7,8,0,3,3,4,1,5,2,0,1,8,8,1,1,7,0,2,4,5,0,0,9,0,2,9,1,4,1,6,3,0,1,1,9,1,9,9,0,1,2,8,3,9,4,5,7,2,6,7,3,4,0,9,0,5,8,5,3,6,9,5,4,1,9,5,9,6,0,7,6,6,8,5,7,1,7,2,1,5,3,5,2,8,9,6,2,8,8,3,8,3,3,9,6,0,1,3,8,0,4,5,5,6,2,1,2,8,8,4,7,0,9,0,5,0,3,1,2,3,8,3,7,5,1,5,5,4,0,5,0,4,8,9,3,2,2,3,3,4,7,7,4,3,2,3,1,2,3,8,3,5,6,5,4,2,3,4,4,6,8,3,4,8,9,5,6,2,0,2,1,2,8,2,7,6,2,3,5,4,8,4,2,7,7,0,3,2,9,8,7,3,9,7,2,6,4,9,5,8,8,7,6,2,8,0,0,4,0,9,4,5,8,1,6,0,8,4,8,7,9,9,2,1,9,2,9,1,1,5,8,9,6,7,2,4,6,5,7,6,6,5,5,5,6,3,1,0,3,4,8,3,5,8,5,5,6,6,6,9,5,1,4,6,4,9,1,9,0,1,5,2,3,6,1,1,7,8,6,7,7,3,1,4,7,0,3,1,8,4,3,2,5,0,4,8,2,1,5,5,8,4,5,2,0,0,2,7,5,8,8,4,8,6,5,3,8,5,3,3,2,3,9,7,3,0,6,1,4,1,2,8,1,6,6,6,3,6,3,4,2,9,3,3,5,9,6,4,8,6,6,2,5,2,3,9,0,3,5,4,2,1,3,2,6,8,6,6,0,1,5,5,9,4,8,3,6,5,8,9,5,2,7,6,1,8,9,4,4,7,5,2,2,1,6,4,6,1,3,4,7,4,8,6,7,6,6,3,6,9,6,7,7,4,8,3,4,0,4,8,7,5,1,6,6,7,1,2,2,4,7,6,6,8,6,4,8,6,2,7,7,7,2,9,7,4,1,6,7,2,4,8,4,7,3,6,7,6,9,8,4,1,8,5,1,6,6,6,5,5,5,6,8,4,5,9,9,1,9,5,7,3,0,6,1,9,8,2,9,3,6,8,9,4,6,7,5,9,9,3,2,1,2,7,3,6,4,9,5,4,7,8,7,7,6,2,1,7,3,3,5,1,0,2,1,7,6,2,2,7,7,9,5,4,4,4,5,1,6,6,0,3,9,4,0,0,6,6,4,1,0,9,5,1,7,4,8,6,8,0,0,4,5,0,0,6,2,1,9,4,0,7,3,0,6,2,8,9,0,8,8,1,9,8,0,2,7,4,0,3,3,8,8,8,1,7,1,8,7,8,7,8,8,0,9,7,0,5,1,5,8,4,1,9,5,4,0,3,5,1,2,8,5,0,0,3,5,5,4,0,3,1,2,3,8,7,2,8,1,0,4,9,0,9,3,6,2,2,0,1,5,3,5,2,6,5,8,1,8,3,1,1,6,0,4,9,2,3,1,7,2,8,0,6,3,3,9,8,8,1,6,8,9,8,3,4,1,4,2,7,0,1,3,9,1,4,0,2,3,2,9,1,1,7,3,3,2,5,6,1,1,9,8,9,0,7,5,8,3,2,2,7,1,1,2,6,8,4,8,6,4,6,9,6,7,1,7,1,3,4,8,5,6,5,9,1,8,3,7,2,1,5,0,5,6,7,0,3,7,5,1,6,1,3,1,7,5,9,1,1,5,6,0,0,1,0,1,6,1,0,0,2,5,5,5,1,5,6,0,2,2,7,3,9,9,6,8,8,0,6,0,7,2,1,3,8,1,6,4,5,6,6,5,0,3,9,3,4,2,3,5,9,6,1,2,7,7,8,5,1,2,6,9,7,9,8,6,6,9,3,8,7,3,0,8,1,1,3,7,3,0,1,5,1,9,2,3,2,5,5,8,8,6,1,2,4,8,1,7,1,9,2,9,3,8,7,1,2,6,3,5,1,0,5,8,9,4,3,6,4,8,9,7,2,4,7,5,8,2,7,5,1,2,4,3,9,7,0,5,2,2,0,1,8,6,2,1,8,8,1,4,4,9,6,1,6,9,9,2,0,9,4,9,8,5,3,4,5,1,4,5,8,7,7,9,6,0,8,0,4,1,3,3,7,1,6,7,9,2,0,6,8,6,3,3,4,8,7,1,6,7,5,1,7,6,2,0,2,5,6,4,5,3,2,1,9,0,8,9,6,8,6,3,9,0,6,1,6,4,6,6,1,4,8,9,4,8,6,1,1,6,0,0,4,4,2,5,9,9,4,9,6,1,6,6,4,2,5,4,8,1,2,6,8,8,2,0,1,3,7,0,8,6,8,8,7,0,4,2,6,3,3,5,3,8,4,3,2,7,7,5,0,3,2,2,8,8,0,5,8,0,6,9,2,6,2,1,4,6,0,3,6,0,1,3,5,3,3,2,4,3,4,6,1,8,0,0,3,9,0,1,2,2,8,4,4,0,8,2,1,1,6,7,6,9,6,5,9,4,8,3,8,7,2,6,2,2,3,8,8,3,1,1,9,7,9,0,9,2,0,4,4,9,4,3,8,8,9,8,9,6,8,6,0,4,3,4,6,3,5,8,7,8,7,5,8,8,4,4,9,2,0,6,7,3,2,8,9,1,7,4,7,2,0,7,8,3,4,6,7,2,0,0,9,5,7,0,4,1,1,5,3,9,7,9,2,1,7,1,5,9,9,8,5,3,3,1,0,0,4,4,6,5,4,1,1,3,2,9,9,4,2,1,4,5,8,7,5,4,9,3,9,6,1,8,3,3,4,0,0,7,3,1,5,8,7,7,3,1,5,3,5,2,8,9,8,3,8,8,5,0,7,0,4,4,3,9,6,8,8,1,7,2,5,4,2,6,4,8,3,4,3,5,3,9,4,7,6,8,2,8,6,9,4,6,9,7,5,0,2,0,3,3,3,1,8,6,0,2,9,2,6,6,5,5,2,1,8,6,0,3,8,5,9,7,8,7,9,2,1,9,8,4,8,8,3,3,3,6,1,3,1,6,0,4,3,8,1,8,8,0,6,4,3,8,1,8,5,7,1,7,7,8,0,5,0,3,0,2,7,7,6,6,0,8,3,0,6,9,9,7,1,6,4,7,0,4,3,7,2,6,9,2,9,8,2,9,6,8,5,7,3,2,7,0,3,2,3,8,5,1,6,4,7,5,6,6,9,3,3,3,0,0,5,5,1,1,5,9,8,9,8,1,0,8,0,7,3,5,5,1,7,8,5,8,6,3,3,7,2,9,1,8,6,1,9,4,2,9,7,3,6,9,9,3,0,1,4,6,0,5,4,8,9,3,4,9,1,9,0,5,0,5,1,4,7,2,1,4,9,4,4,6,6,9,1,4,5,7,4,4,9,8,2,6,2,6,3,9,8,4,8,8,9,0,9,0,2,6,4,4,8,0,5,4,1,3,3,9,1,1,7,3,9,1,1,2,5,0,2,0,4,1,8,4,2,9,2,7,8,6,9,6,0,3,1,4,1,5,4,5,7,7,0,4,2,3,9,4,4,8,4,6,1,3,1,7,8,6,5,2,3,8,6,9,0,4,6,6,4,3,7,3,8,6,2,2,5,7,9,6,1,0,1,2,9,2,1,8,4,5,3,3,5,1,1,3,0,9,4,8,2,3,5,0,6,6,3,7,0,5,5,8,6,9,8,9,1,7,9,7,7,0,2,4,1,3,1,8,0,6,7,8,9,1,4,7,7,8,6,7,5,3,9,7,6,8,7,2,8,0,5,9,5,2,5,8,3,4,9,2,6,8,7,6,5,9,5,7,6,5,9,0,6,8,9,6,7,6,9,2,8,5,3,7,5,6,9,1,2,7,2,2,5,8,4,5,7,3,7,8,5,2,8,9,8,9,1,2,3,8,9,6,8,3,2,2,9,3,6,3,7,6,7,0,9,2,9,5,0,6,1,6,5,3,8,4,8,9,0,7,9,1,9,7,3,3,7,8,4,4,3,7,6,5,4,4,5,5,0,0,0,4,1,7,8,1,9,3,8,9,1,1,3,1,3,1,3,4,2,4,2,2,2,4,4,6,8,3,0,0,3,2,4,6,4,6,2,4,1,1,2,4,4,0,8,6,7,9,2,9,4,7,4,1,5,0,1,8,7,7,6,9,3,5,6,3,8,6,1,9,3,1,8,7,9,3,3,3,3,4,9,7,1,5,0,0,7,2,1,5,3,7,1,4,3,4,5,7,7,0,1,2,6,8,3,1,0,3,4,1,2,8,4,7,1,9,6,7,2,3,5,6,2,0,2,5,7,1,9,5,0,9,0,6,3,8,5,3,6,8,1,9,9,9,7,4,7,4,9,7,0,3,2,9,8,3,5,6,8,4,1,1,2,0,2,7,8,4,4,9,2,2,8,8,0,0,0,2,0,9,9,0,1,7,2,4,1,7,8,2,5,1,7,4,8,4,4,6,0,8,7,7,8,5,5,5,1,6,2,2,1,5,2,9,5,8,5,5,0,0,9,4,0,1,1,1,9,7,5,5,6,9,0,8,4,4,1,8,7,3,5,3,9,2,5,7,8,9,7,3,7,2,2,9,4,4,8,7,0,8,6,7,1,2,8,9,7,0,5,2,8,1,1,8,0,4,3,7,6,3,5,9,4,3,5,6,0,8,2,4,6,6,9,0,2,6,5,1,6,1,2,5,1,2,9,9,2,9,2,4,3,8,6,5,9,3,0,0,1,1,7,1,1,1,1,4,1,3,5,5,5,1,6,8,5,0,5,0,7,7,9,0,0,0,4,5,4,3,9,2,0,1,7,5,3,2,2,4,7,4,9,8,7,4,3,1,0,7,1,4,6,3,5,1,0,4,1,1,3,3,7,0,1,8,6,0,1,4,4,8,3,2,9,6,3,7,1,6,6,0,5,4,0,9,3,8,9,2,7,2,0,7,9,9,8,1,1,9,0,8,4,9,0,2,3,3,0,3,0,4,5,8,7,7,7,8,2,4,6,0,5,6,6,0,2,2,8,5,2,6,2,7,0,1,4,2,1,3,0,9,3,8,4,1,1,6,4,0,0,4,4,7,9,2,0,4,1,6,5,2,7,7,6,4,4,1,3,4,5,7,1,6,0,8,4,6,1,3,1,4,0,2,9,1,6,2,7,2,1,7,6,1,8,0,5,4,1,7,2,6,2,5,0,5,1,3,1,8,8,0,6,7,9,4,2,8,1,3,2,3,0,5,1,0,7,8,4,1,1,6,3,0,5,5,2,9,0,5,4,9,3,7,3,3,6,6,9,3,9,8,2,4,9,7,2,7,1,4,4,9,7,9,1,8,8,8,5,7,4,5,6,1,0,3,6,6,4,3,0,7,2,6,2,6,6,0,0,0,5,8,8,4,3,4,8,5,8,3,4,4,0,9,5,7,1,4,9,6,8,1,4,8,6,4,4,2,7,1,2,1,2,3,6,2,4,6,1,0,3,8,5,4,3,2,3,4,4,8,0,7,0,3,9,7,8,0,1,9,0,7,5,7,6,6,6,2,4,6,6,5,2,7,3,4,1,6,0,9,0,1,6,8,8,7,0,8,0,0,9,8,6,3,3,0,2,2,8,6,1,3,5,8,0,6,6,8,2,1,2,8,9,9,7,3,9,0,3,7,0,6,5,8,3,2,7,7,5,6,3,0,6,5,7,5,3,8,7,5,2,4,1,0,2,3,4,2,1,0,9,2,1,5,9,5,1,2,5,5,8,0,5,1,4,7,1,7,0,7,1,9,3,8,2,8,9,5,7,9,7,9,6,2,7,4,0,3,2,7,3,0,7,9,8,5,3,8,2,4,4,4,2,1,6,2,1,3,0,5,1,4,9,8,2,0,7,5,4,9,8,9,8,9,9,5,1,0,6,7,3,5,9,0,4,8,0,6,4,8,7,1,1,3,5,0,0,3,8,7,4,5,2,8,7,7,7,1,6,7,0,7,4,8,7,5,7,5,3,3,0,3,2,4,8,8,3,1,3,0,9,7,4,6,8,0,7,4,0,4,7,1,1,0,7,8,9,1,9,7,3,2,8,6,7,5,0,2,8,0,6,3,5,7,5,7,9,7,0,8,9,9,7,3,5,3,4,1,4,6,4,1,6,1,3,5,7,7,3,0,7,3,3,4,8,4,2,5,3,6,1,7,5,1,8,9,7,0,0,6,2,6,6,3,1,2,9,2,5,7,0,6,0,5,3,6,9,7,2,1,3,5,0,0,2,2,2,2,1,9,0,2,3,7,7,6,9,4,7,3,9,7,7,4,5,4,4,3,0,8,1,1,6,8,2,4,1,7,3,8,6,8,2,4,2,8,0,5,9,8,3,6,1,7,3,8,8,0,6,6,0,3,6,6,9,9,7,5,6,1,1,9,6,8,1,3,4,4,5,7,0,9,3,2,5,5,2,3,4,8,9,9,2,5,8,3,4,7,6,6,3,5,3,4,6,0,2,6,3,8,5,9,6,1,5,5,5,7,5,3,0,3,3,2,6,8,1,0,2,3,1,4,7,6,8,2,5,3,9,3,5,4,0,4,7,4,3,5,3,6,9,3,9,4,8,6,7,7,6,4,8,3,4,7,3,4,4,1,0,6,1,1,0,0,7,6,4,6,9,8,4,3,9,3,8,6,5,4,7,8,9,7,1,3,8,8,2,5,6,2,1,6,3,5,0,9,0,6,4,5,9,2,3,2,8,2,9,3,7,0,4,1,9,2,0,4,0,8,2,3,8,1,4,2,3,4,3,4,1,5,4,0,1,7,0,8,4,0,8,6,5,6,9,2,0,2,4,2,9,8,8,2,8,9,8,9,2,9,9,7,8,3,7,3,2,1,7,2,3,0,4,1,5,6,5,5,0,2,8,3,0,3,8,9,4,7,9,6,8,2,4,8,4,6,6,1,4,5,8,2,3,5,1,8,9,6,5,2,8,3,7,5,3,1,9,7,5,3,3,2,0,3,0,6,1,1,5,0,7,1,4,5,7,8,1,8,5,9,3,1,9,7,0,4,0,8,1,7,5,7,0,7,8,6,1,3,9,1,2,2,8,4,3,5,0,1,4,7,9,9,1,1,3,4,3,4,0,1,3,8,9,6,3,6,6,3,6,2,4,0,1,0,9,8,1,0,8,4,3,4,6,5,6,0,7,2,5,0,2,2,8,5,9,1,2,1,2,8,6,6,1,0,7,9,1,5,7,9,8,7,1,7,3,8,0,3,0,6,6,3,6,4,7,0,1,2,9,2,1,6,9,4,2,9,1,8,0,7,3,1,3,9,8,5,4,7,0,5,1,5,9,8,0,7,0,7,8,7,4,1,5,1,1,1,5,1,3,3,6,1,2,8,1,4,0,6,6,4,1,2,7,2,6,7,4,1,7,7,7,7,9,3,2,2,7,1,2,6,4,9,1,5,2,1,6,7,5,7,3,5,2,8,8,7,1,5,6,0,1,6,2,2,2,3,1,2,9,0,2,3,0,2,1,8,0,9,2,8,5,5,9,0,9,5,6,0,9,8,9,2,7,1,5,4,3,2,1,3,9,3,7,9,6,6,0,0,8,2,9,9,1,2,7,1,4,9,6,2,1,9,6,7,2,2,8,2,0,1,3,8,7,8,2,2,2,0,0,8,7,2,2,2,5,4,0,0,8,2,2,0,6,5,5,3,6,4,3,8,6,2,3,8,6,3,8,9,8,3,9,9,4,9,3,9,7,8,5,0,9,2,6,2,3,9,5,4,2,3,4,2,1,5,6,6,2,5,0,9,2,3,8,6,2,0,4,9,2,3,0,2,1,4,6,1,2,0,1,3,0,4,3,8,7,1,9,6,5,3,8,5,3,4,5,1,5,0,3,4,8,0,5,5,5,0,1,4,6,9,5,8,8,7,4,4,6,8,3,6,2,3,5,3,4,4,0,3,2,7,9,8,1,0,3,7,5,5,5,4,3,1,3,5,7,9,9,6,1,1,1,3,4,5,7,5,6,9,5,7,9,0,5,4,4,6,5,7,7,4,5,1,8,9,6,9,9,6,3,8,7,8,2,0,2,3,6,7,2,5,5,4,0,4,6,6,0,4,8,3,0,0,3,7,6,4,7,2,2,4,0,9,3,6,7,4,6,9,3,0,1,6,5,3,8,5,9,6,3,5,1,7,5,8,0,4,5,7,8,7,2,3,7,6,4,2,7,3,1,0,6,9,1,2,7,5,2,6,6,8,9,7,3,4,9,9,7,6,2,1,3,9,0,6,8,7,7,2,5,5,0,3,3,2,8,1,2,0,5,6,9,0,3,4,7,3,9,2,5,8,1,1,0,7,};
    root = CreateBinaryTree(num, -1001);
    ser = serialize(root);
    deser = deserialize(ser);

    num = { 1};
    root = CreateBinaryTree(num, -1001);
    ser = serialize(root);
    deser = deserialize(ser);

    num = { 1,2,3,-1001,-1001,4,5 };
    root = CreateBinaryTree(num, -1001);
    ser = serialize(root);
    deser = deserialize(ser);
}
void TestCase_113()
{
    vector<int> num;
    struct TreeNode* root = NULL;
    int nr, nc;
    int* nnc = &nc;

    num = { 5,4,8,11,-1001,13,4,7,2,-1001,-1001,-1001,-1001,5,1 };
    root = CreateBinaryTree(num, -1001);
    pathSum(root, 22, &nr, &nnc);
}
void TestCase_103()
{
    vector<int> num ;
    struct TreeNode* root = NULL;
    int nr, nc;
    int *nnc = &nc;

    //num = { 3,9,20,-101,-101,15,7 };
    //root = CreateBinaryTree(num);
    //zigzagLevelOrder(root, &nr, &nnc);

    num = { 69,73,68,18,20,18,39,7,-3,13,-1,42,5,93,70,63,17,-101,91,-4,30,-101,-1,64,-4,16,49,48,78,51,43,92,45,-101,53,9,36,80,-6,58,78,-101,-101,41,81,89,67,71,-101,25,-101,82,54,28,14,61,57,35,5,83,9,18,-101,-9,-9,50,92,93,-101,0,80,62,1,28,29,27,89,21,-101,85,-9,-101,56,56,-9,-101,-101,43,-101,29,97,-7,-101,35,25,90,67,53,18,61,7,23,81,37,19,26,2,0,19,-101,-101,77,37,-2,-101,49,39,28,1,37,11,87,83,68,55,53,33,-2,22,7,52,-101,14,-101,18,50,97,-8,-7,-101,21,59,72,27,-101,64,-101,-101,47,-101,-101,38,46,-101,-101,99,-101,-101,48,13,85,78,7,64,43,59,71,11,37,12,37,50,2,-101,-101,89,87,-101,78,97,-101,31,86,37,96,34,38,6,36,-101,-101,99,63,-101,12,-101,82,-101,81,70,19,-101,81,32,-101,-101,-101,-101,79,10,-101,91,48,-3,94,65,-101,20,26,96,21,92,91,-101,89,9,74,-101,-101,96,-101,64,67,50,96,-101,-101,-101,-101,-101,-101,40,78,-101,27,3,17,-101,-101,2,45,-101,-101,-101,-101,-101,13,-101,-101,17,45,69,30,-101,-101,43,-101,4,13,-6,66,6,-101,16,48,55,98,69,57,-101,5,9,65,-9,55,2,-101,-101,-101,-101,-101,-101,68,-101,-101,-101,5,61,51,-101,-101,32,43,-101,35,20,-101,-7,38,30,1,80,-101,-101,42,86,42,-101,-101,-101,-101,47,-101,-101,-101,62,29,-9,83,60,71,48,-101,24,-101,76,6,65,18,95,29,11,-101,38,-101,-101,-101,-101,21,3,6,23,36,-101,45,-101,34,-101,-101,-101,-101,-101,-101,41,-101,57,13,18,92,43,83,-101,-101,-101,-101,-101,-101,-101,2,-4,97,-101,93,-101,62,-101,-101,48,18,71,92,53,89,-101,-101,-101,95,-101,16,-101,-101,-101,83,87,5,-101,-101,3,-8,-4,65,-101,-101,-101,22,-101,31,-101,-101,-101,63,-101,-101,62,-101,57,12,85,45,23,55,-101,-101,-101,81,83,23,-101,3,-101,83,-101,-4,-101,-101,-101,-101,-101,64,-101,15,50,57,-101,-101,-101,4,-101,-101,-101,29,-101,-101,87,-101,22,92,-101,-101,67,90,-101,93,47,46,-101,-101,-101,28,72,18,59,25,3,74,-101,-101,-101,-5,28,-1,61,15,-101,-101,-101,-101,79,-101,16,-101,-101,59,47,-7,98,31,50,-101,-101,-101,-101,19,-101,93,-101,22,-101,-101,-5,40,-101,-101,-101,75,30,-101,7,53,76,-101,-101,-101,-101,-101,68,19,-101,63,41,91,-101,43,-101,49,-101,-101,-101,-101,-101,46,-101,-101,87,74,49,1,21,62,6,34,77,-101,-101,-101,-101,-101,-101,-9,61,-101,-101,-101,7,-101,45,-101,-101,63,-101,-101,7,-101,-101,16,86,-101,-101,63,-101,61,72,-101,13,-101,24,91,-101,-101,59,-101,-101,48,14,77,-101,-101,-101,-101,92,-101,-101,-101,-101,-101,-101,84,-101,-101,76,82,63,84,84,94,-101,-101,-101,-101,-101,47,40,-101,-101,-101,-101,75,20,-101,-101,-101,-9,-101,-101,24,74,-101,51,-101,-101,91,-101,83,17,-101,-101,-101,42,49,88,57,85,1,-101,94,-101,28,36,78,-101,53,-101,27,25,46,97,58,-101,-101,-101,-101,-101,-101,-101,-101,12,33,-101,-101,6,-101,-101,-101,87,-101,-101,-101,-101,-101,-101,-101,9,-101,83,-101,-101,-101,90,11,-101,61,-101,89,-101,46,-101,86,81,-101,-101,-101,-101,-101,-101,-101,53,-101,-101,59,-101,-101,-101,-101,-101,-101,-101,29,-101,47,97,0,-101,-101,-101,-101,9,-101,17,-101,91,45,9,61,21,-101,-101,64,-101,69,-101,44,-101,-101,-101,-101,12,-101,2,-8,88,-101,-101,-101,-101,-101,-8,-101,93,-101,-101,-101,86,-101,-101,97,-101,-101,-101,-101,72,-101,-101,-101,-101,-101,50,-101,-101,-101,-101,-101,47,70,-101,62,-101,-3,-5,59,15,-101,-3,37,-101,-101,-101,-101,20,-2,-101,8,90,-101,-101,-101,61,-101,-101,-101,-101,-101,-101,-101,15,12,95,-101,-101,73,11,76,76,49,-101,-101,51,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,42,-101,-101,-9,-101,-101,-101,-101,-101,-101,-101,-101,80,-101,-101,70,31,78,98,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,7,-101,-101,-101,-101,57,-101,-101,-101,-101,-3,-101,-101,-7,-101,31,42,-101,-101,-101,-101,62,17,7,-101,-101,63,-101,-101,-101,-101,83,51,-101,76,77,-101,-101,40,-101,-101,95,-101,27,55,61,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,-101,95,-101,93,19,-101,37,-101,73,-101,-101,-101,-101,-101,75,-101,-101,-101,-101,-101,22,-101,-101,-101,-101,-101,-7,99,-101,-101,-101,-101,-101,94,63,-101,-101,-101,-101,-101,-101,-101,39,77,-101,-2,15,-101,69,33,9,-101,-101,-101,-101,-101,-101,-101,-101,-101,42,-101,-101,-101,69,35,-101,36,-101,11,-101,-101,-101,52,-101,-101,-101,-101,-101,-101,-101,51,50,-101,-101,-101,-101,-101,-101,30,-101,-101,-101,-101,-101,63,-101,-101,-101,-101,-101,-101,56,28 };
    root = CreateBinaryTree(num, -101);
    zigzagLevelOrder(root, &nr, &nnc);
}
void TestCase_108()
{
    vector<int> cost;
    cost = { -1,0,1,2 };
    sortedArrayToBST(cost.data(), (int)cost.size());
}

void TestCase_1823()
{
    int expect, output;
    expect = 3;
    output = findTheWinner(3,1);
    COMPVALUE(expect, output);

    expect = 1;
    output = findTheWinner(6, 5);
    COMPVALUE(expect, output);
}

void TestCase_143()
{
    vector<int> nums1;

    ListNode* output = NULL;
    struct ListNode* headA;

    nums1 = { 1,2,3,4,5 };
    headA = CreateListNode(nums1);
    reorderList(headA);
}

void TestCase_25()
{
    vector<int> nums1;

    ListNode* output = NULL; 
    struct ListNode* headA;

    nums1 = { 1,2,3,4,5 ,6,7};
    headA  = CreateListNode(nums1);
    output = reverseKGroup(headA, 3);

    nums1 = { 1,2,3,4,5 };
    headA = CreateListNode(nums1);
    output = reverseKGroup(headA, 2);
}

void TestCase_120()
{
    vector<vector<int>> matrix;
    int** p;
    int row = 3, col = 3;
    int expect, output;

    matrix = { {-1,0,0},{3,2,0},{-3, 1, -1} };
    row = 3, col = 3;
    expect = -1;
    p = matrix2addr(matrix);
    output = minimumTotal(p, row, &col);
    COMPVALUE(expect, output);

    matrix = { {-1,0,0},{2,3,0},{1, -1, -3}};
    row = 3, col = 3;
    expect = -1;
    p = matrix2addr(matrix);
    output = minimumTotal(p, row, &col);
    COMPVALUE(expect, output);

    matrix = { {2,0,0,0},{3,4,0,0},{6,5,7,0},{4,1,8,3} };
    row = 4, col = 4;
    expect = 11;
    p = matrix2addr(matrix);
    output = minimumTotal(p, row, &col);
    COMPVALUE(expect, output);
}

void TestCase_62()
{
    int output;
    output = uniquePaths(3, 3);
}

void TestCase_746()
{
    vector<int> cost;
    int output;
    cost = { 1, 100,1,1,1,100,1,1,100,1 };
    output = minCostClimbingStairs(cost.data(), (int)cost.size());
}

void TestCase_187()
{
    string s;
    int anssize;

    s = "TGCTCCTGTCACAACTTCTTTACCAGCCTGTTTTTCTAGAGTCGGCTCAAAACCTGCCTTTATGCGCAGCTGTCCACGAGAATTTCATGTTATCGAGGACCGCGATATACCCAATCGCGCGCCCCAGAAAAAAGAGTCTTACCAGATGTATACGGTGACGACCCAGTGGGTAAGACCGCTCTGCTCAGCGACCCGTCCATACCCACAGTCAGCCATGTGTGACATATCAGCGTGCATTCTTGATCTGTATGGGTGCGCTGCCCCCGCACTTGATGGGGTATGTGATGACTCCGCTCGGTAAGCAAGACCCTGGGGGTTCGGACGTAGGGTATACCCGAACTTCACGTATGCGGACACCAACGCACGTGCCAATTTATCTAACGTATGTCTCCATGCCGCCCAGAAGGTTAAAGTGGACCGCCGTTCGTATACTGTTTCTGCAATTGTGTGCGGCAGCACCAGGTAGAGAGCATTCTATTTCGCTAGCTAGTAAATCTACTTCACCGAGTCTGGAAGCTCCAATCGCTGTTTACAAACTTTTTGCCCCTGCGTGGGTCAGGCCATGTCCCGTTCCCGAGGATTCTAGCACTGACCTAGCCCTATATCACGAGCCGGGTTTTCTTAAAATAGAGATCGGGACGTTAAGGTCTTATGAACGGCTTCAGCTATCTTCCGCTTACCAACTGAGCCGAACTATCTCCGGGTGTTACATGGATCCTAAAATGCTCTCCAATTTTGCCCCTGCATGGTATTTCTCTTGAGACTACTGGATCTACCTGGGTTGTGCATGTTTCGTGTCTCTTCCGACGTTCGACAATTGGGGGCGACGCTTTAAGTTCTACTACGGTGAGATGCACATCCCACGGACGCCCTTTTCCTTTGGCTCTTCCTACGTTCGCGAGCGGTCCTGTAGGACAGTTGCTTTATGCCAACTTTTACGAGGGTGGAATACAGTATCGCCATGACACTCTGAAAAAGGATGGAAGACCTGAGATTCAC";
    findRepeatedDnaSequences(&*s.begin(), &anssize);

    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    findRepeatedDnaSequences(&*s.begin(), &anssize);

    /*
    "TGCTCCTGTCACAACTTCTTTACCAGCCTGTTTTTCTAGAGTCGGCTCAAAACCTGCCTTTATGCGCAGCTGTCCACGAGAATTTCATGTTATCGAGGACCGCGATATACCCAATCGCGCGCCCCAGAAAAAAGAGTCTTACCAGATGTATACGGTGACGACCCAGTGGGTAAGACCGCTCTGCTCAGCGACCCGTCCATACCCACAGTCAGCCATGTGTGACATATCAGCGTGCATTCTTGATCTGTATGGGTGCGCTGCCCCCGCACTTGATGGGGTATGTGATGACTCCGCTCGGTAAGCAAGACCCTGGGGGTTCGGACGTAGGGTATACCCGAACTTCACGTATGCGGACACCAACGCACGTGCCAATTTATCTAACGTATGTCTCCATGCCGCCCAGAAGGTTAAAGTGGACCGCCGTTCGTATACTGTTTCTGCAATTGTGTGCGGCAGCACCAGGTAGAGAGCATTCTATTTCGCTAGCTAGTAAATCTACTTCACCGAGTCTGGAAGCTCCAATCGCTGTTTACAAACTTTTTGCCCCTGCGTGGGTCAGGCCATGTCCCGTTCCCGAGGATTCTAGCACTGACCTAGCCCTATATCACGAGCCGGGTTTTCTTAAAATAGAGATCGGGACGTTAAGGTCTTATGAACGGCTTCAGCTATCTTCCGCTTACCAACTGAGCCGAACTATCTCCGGGTGTTACATGGATCCTAAAATGCTCTCCAATTTTGCCCCTGCATGGTATTTCTCTTGAGACTACTGGATCTACCTGGGTTGTGCATGTTTCGTGTCTCTTCCGACGTTCGACAATTGGGGGCGACGCTTTAAGTTCTACTACGGTGAGATGCACATCCCACGGACGCCCTTTTCCTTTGGCTCTTCCTACGTTCGCGAGCGGTCCTGTAGGACAGTTGCTTTATGCCAACTTTTACGAGGGTGGAATACAGTATCGCCATGACACTCTGAAAAAGGATGGAAGACCTGAGATTCAC
View All
Output
["TATACGGTGA","TAGCTAGTAA","TTTTGCCCCT","TTTGCCCCTG","TTGCCCCTGC"]
Expected
["TTTTGCCCCT","TTTGCCCCTG","TTGCCCCTGC"]
    */
}

void TestCase_43() 
{
    string num1, num2;

    num1 = "123";
    num2 = "456";
    multiply(&*num1.begin(), &*num2.begin());
}
void TestCase_49() 
{
    vector<string> vstr= { "eat","tea","tan","ate","nat","bat" };
    char** strs;
    int grps,nums, i, len;
    int *nn = &nums;

    strs = (char**)malloc(sizeof(char*) * vstr.size());
    for (i = 0; i < (int)vstr.size(); i++) {
        len = (int)vstr[i].size();
        strs[i] = (char*)malloc(len + 1);
        memcpy(strs[i], vstr[i].c_str(), len);
        strs[i][len] = '\0';
    }

    groupAnagrams((char**)strs, (int)vstr.size(), &grps, &nn);
}
void TestCase_290()
{
    string a, b;
    bool expect, output;

    a = "abc";
    b = "b c a";
    expect = true;
    output = wordPattern(&*a.begin(), &*b.begin());
    COMPVALUE(expect, output);

    a = "e";
    b = "eukera";
    expect = true;
    output = wordPattern(&*a.begin(), &*b.begin());
    COMPVALUE(expect, output);

    a = "aaa";
    b = "aa aa aa aa";
    expect = false;
    output = wordPattern(&*a.begin(), &*b.begin());
    COMPVALUE(expect, output);

    a = "abba";
    b = "dog cat cat dog";
    expect = true;
    output = wordPattern(&*a.begin(), &*b.begin());
    COMPVALUE(expect, output);

    a = "abba";
    b = "dog dog dog dog";
    expect = false;
    output = wordPattern(&*a.begin(), &*b.begin());
    COMPVALUE(expect, output);    
}

void TestCase_435()
{
    vector<vector<int>> matrix;
    int** p;

    matrix = { {1,2},{1,2},{1,2} };
    int row = 3, col = 2;
    p = matrix2addr(matrix);

    int output = eraseOverlapIntervals(p, row, &col);
}

void TestCase_415()
{
    string a, b;
    a = "9133";
    b = "0";
    addStrings(&*a.begin(), &*b.begin());
}

void TestCase_240()
{
    vector<vector<int>> matrix;
    int col = 5;
    bool expect, output;

    matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    expect = true;
    output = searchMatrixII(matrix, 5, &col, 5);
    COMPVALUE(expect, output);
    
    matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,1,17,24},{18,21,23,26,30} };
    col = 5;
    expect = true;
    output = searchMatrixII(matrix, 5, &col, 5);
    COMPVALUE(expect, output);
    expect = false;
    output = searchMatrixII(matrix, 5, &col, 20);
    COMPVALUE(expect, output);
}

void TestCase_59()
{
    int nr, * nc;
    generateMatrix(4, &nr, &nc);


    generateMatrix(5, &nr, &nc);
}

void TestCase_706()
{
    int val;
    MyHashMap* obj = myHashMapCreate();
    myHashMapPut(obj, 1, 1);
    myHashMapPut(obj, 2, 2);
    val = myHashMapGet(obj, 1);
    val = myHashMapGet(obj, 3);
    myHashMapPut(obj, 2, 1);
    val = myHashMapGet(obj, 2);
    myHashMapRemove(obj, 2);
    val = myHashMapGet(obj, 2);
    myHashMapFree(obj);
}
void TestCase_56()
{
    int** p;
    int nr, nl;
    int* nnl = &nl;

    int matrix[2][2] = { {1,4}, {0,4} };
    int col = 2;

    p = (int**)malloc(sizeof(int*) * 2);
    for (int i = 0; i < 2; i++) {
        p[i] = (int*)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++) {
            p[i][j] = matrix[i][j];
        }
    }

    merge(p, 2, &col, &nr, &nnl);

}
void TestCase_75()
{
    vector<int> input;

    input = { 2,0,1 };
    sortColors(input.data(), (int)input.size());
}

void TestCase_15()
{
    vector<int> input;

    input = { 0,5,1,9,6,7,19,11,3,8,4 };
    quicksort(input.data(), 0, (int)input.size()-1);
}

void TestCase_136()
{
    vector<int> input;
    int output,expect;

    input = { 4,1,2,1,2 };
    expect = 4;
    output = singleNumber(input.data(), (int)input.size());

    input = { 3,9,20,-1,-1,15,7 };
}

void TestCase_438()
{
    string s, p;
    int retsize;

    //s = "cbaebabacd";
    //p = "abc";
    //findAnagrams(&*s.begin(), &*p.begin(), &retsize);

    //s = "abab";
    //p = "ab";
    //findAnagrams(&*s.begin(), &*p.begin(), &retsize);

    s = "afdkljflsdkjfsdlkjfdslkjfdslkjfkljlkjlkfdjslkfjsdlkjsdflksdjflkdsjfldskjksldfjlksdjflkdsjfsjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjfsdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    p = "z";
    findAnagrams(&*s.begin(), &*p.begin(), &retsize);
}


void TestCase_784()
{
    string s;
    int retsize;

    s = "3z4";
    letterCasePermutation(&*s.begin(), &retsize);
}

void TestCase_77()
{
    int nr, nl;
    int* nnl = &nl;
    combine(4, 2, &nr, &nnl);
}

void TestCase_509()
{
    COMPVALUE(0, fib(0));

    COMPVALUE(1, fib(1));

    COMPVALUE(1, fib(2));

    COMPVALUE(2, fib(3));

    COMPVALUE(3, fib(4));

    COMPVALUE(5, fib(5));
}

void TestCase_1544()
{
    string s;
    char *output;

    s = "s";
    output = makeGood(&*s.begin());
}


void TestCase_542()
{
    int** p;
    int nr, nl;
    int* nnl = &nl;

    int matrix[3][3] = { {0,0,0}, {0,1,0}, {1,1,1 } };
    int col = 3;

    p = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        p[i] = (int*)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            p[i][j] = matrix[i][j];
        }
    }
    updateMatrix(p, 3, &col, &nr, &nnl);

    int bb[5][3] = { {0,1,0}, {0,1,0}, {0,1,0 }, {0,1,0}, {0,1,0 } };
    col = 3;
    p = (int**)malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        p[i] = (int*)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            p[i][j] = bb[i][j];
        }
    }

    updateMatrix(p, 5, &col, &nr, &nnl);
};

void TestCase_212()
{
    char** board;
    char** words;
    int size;
    char matrix[4][4] = { { 'o','a','a','n' }, {'e', 't', 'a', 'e'},{'i', 'h', 'k', 'r'},{'i', 'f', 'l', 'v'}};
    char wordss[4][4] = { { 'o','a','t','h' }, {'p', 'e', 'a', 0},{'e', 'a', 't', 0},{'r', 'a', 'i', 'n'} };
    int col = 4;

    board = (char**)malloc(sizeof(char*) * 4);
    words = (char**)malloc(sizeof(char*) * 4);
    for (int i = 0; i < 4; i++) {
        board[i] = (char*)malloc(sizeof(char) * 4);
        words[i] = (char*)malloc(sizeof(char) * 5);
        memset(words[i], 0, 5);
        for (int j = 0; j < 4; j++) {
            board[i][j] = matrix[i][j];
            words[i][j] = wordss[i][j];
        }
    }

    findWords(board, 4, &col, words, 4, &size);
}

void TestCase_387()
{
    string s;
    int expect;
    int output;

    s = "aabb";
    expect = -1;
    output = firstUniqChar(&*s.begin());
    COMPVALUE(expect, output);

    s = "loveleetcode";
    expect = 2;
    output = firstUniqChar(&*s.begin());
    COMPVALUE(expect, output);
}

void TestCase_102()
{
    vector<int> input;
    TreeNode* root;
    int nr, nl;
    int* nnl = &nl;

    input = { 3,9,20,-1,-1,15,7 };

    root = CreateBinaryTree(input);
    levelOrder(root,&nr, &nnl);
}

void TestCase_567()
{
    string s1, s2;
    bool expect;
    bool output;

    s1 = "ab";
    s2 = "eidbaooo";
    expect = true;
    output = checkInclusion(&*s1.begin(), &*s2.begin());
    COMPVALUE(expect, output);

    s1 = "ab";
    s2 = "eidboaoo";
    expect = false;
    output = checkInclusion(&*s1.begin(), &*s2.begin());
    COMPVALUE(expect, output);
}

void TestCase_3()
{
    string s;
    int expect;
    int output;

    s = " ";
    expect = 1;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);


    s = "tmmzuxt";
    expect = 5;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);

    s = "abcabcbb";
    expect = 3;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);

    s = "bbbbb";
    expect = 1;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);

    s = "pwwkew";
    expect = 3;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);
}

void TestCase_118()
{
    /*int nr, nl;
    int* nnl = &nl;*/
    //generate(5, &nr, &nnl);
    generate(5);
}

void TestCase_566()
{
    int** p;
    int nr, nl;
    int* nnl = &nl;

    int matrix[3][4] = { {1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2 } };
    int col = 4;

    p = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        p[i] = (int*)malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++) {
            p[i][j] = matrix[i][j];
        }
    }
    matrixReshape(p, 3, &col, 4,3, &nr, &nnl);


    int bb[2][2] = { {1, 2}, {3,4}};
    col = 2;
    p = (int**)malloc(sizeof(int*) * 2);
    for (int i = 0; i < 2; i++) {
        p[i] = (int*)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++) {
            p[i][j] = bb[i][j];
        }
    }
    matrixReshape(p, 2, &col, 1, 4, &nr, &nnl);
};

void TestCase_557()
{
    string s;
    char* output;
    
    s = "Let's take LeetCode contest";
    COUTARRAY((&*s.begin()), s.length());
    output =  reverseWordsIII(&*s.begin());
    COUTARRAY((&*s.begin()), s.length());
}

void TestCase_88()
{
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    merge(nums1.data(), (int)nums1.size(), 3, nums2.data(), (int)nums2.size(), 3);
}

void TestCase_53()
{
    int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
    int expect = 6;
    int output;
    output = maxSubArray(nums, 9);
    COMPVALUE(expect, output);
}

void TestCase_167()
{
    vector<int> nums;
    int target;
    vector<int> expect;
    int rSize;
    int* output;

    nums = { 2,7,11,15 };
    target = 9;
    expect = { 1,2 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 2,3,4 };
    target =6;
    expect = { 1,3 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { -1,0 };
    target = -1;
    expect = { 1,2 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 3,3 };
    target = 6;
    expect = { 1,2 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);
}

void TestCase_217()
{
    int nums[4] = {1,2,3,1};
    containsDuplicate(nums, 4);
}
void TestCase_766()
{
    int matrix[3][4] = { {1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2 } };
    int** p;
    bool expect = true;
    bool output;
    int col = 4;

    p = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        p[i] = (int*)malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++) {
            p[i][j] = matrix[i][j];
        }
    }

    output = isToeplitzMatrix(p, 3, &col);
    COMPVALUE(expect, output);
};

void TestCase_189()
{
    vector<int> nums;

    nums = { 1,2,3,4,5,6,7 };
    COUTARRAY(nums.data(), (int)nums.size());
    rotate(nums.data(), (int)nums.size(), 3);
    COUTARRAY(nums.data(), (int)nums.size());

    nums = { -1, -100, 3, 99 };
    COUTARRAY(nums.data(), (int)nums.size());
    rotate(nums.data(), (int)nums.size(), 2);
    COUTARRAY(nums.data(), (int)nums.size());
}
void TestCase_392()
{
    string s, t;
    bool expect;
    bool output;

    s = "abc";
    t = "ahbgdc";
    expect = true;
    output = isSubsequence(&*s.begin(), &*t.begin());
    COMPVALUE(expect, output);
}

void TestCase_205()
{
    string s, t;
    bool expect;
    bool output;

    s = "egg";
    t = "add";
    expect = true;
    output = isIsomorphic(&*s.begin(), &*t.begin());
    COMPVALUE(expect, output);
}

void TestCase_724()
{
    vector<int> nums;
    int expect;
    int output;

    nums = { 1,7,3,6,5,6 };
    expect = 3;
    output = pivotIndex(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 1,2,3 };
    expect = -1;
    output = pivotIndex(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 2,1,-1 };
    expect = 0;
    output = pivotIndex(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);
}
void TestCase_1480()
{
    vector<int> nums;
    vector<int> expect;
    int* output;
    int  retrunsize = 0;

    nums = { 1,2,3,4 };
    expect = { 1,3,6,10 };
    output = runningSum(nums.data(), (int)nums.size(), &retrunsize);
    COMPARRAY(expect.data(), expect.size(), output, retrunsize);
    FREEMEM(output);
}

void TestCase_1047()
{
    string s;
    string expect;
    char* output;

    s = "abbaca";
    expect = "ca";
    output = removeDuplicates(&*s.begin());
    cout << "expect:" << expect << endl;
    cout << "output:" << output << endl;
    FREEMEM(output);

    s = "azxxzy";
    expect = "ay";
    output = removeDuplicates(&*s.begin());
    cout << "expect:" << expect << endl;
    cout << "output:" << output << endl;
    FREEMEM(output);
}
void TestCase_523()
{
    vector<int> nums;
    int k;
    bool expect;

    nums = { 1,0 };
    k = 2;
    expect = false;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 5,0,0,0 };
    k = 3;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23, 2, 4, 6, 6 };
    k = 7;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23,2,4,6,7 };
    k = 6;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23,2,6,4,7 };
    k = 6;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23,2,6,4,7 };
    k = 13;
    expect = false;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));
}

void TestCase_142()
{
    cout << "detectCycle" << endl;
}

void TestCase_1662()
{
    char word1[2][4] = { "ab", "c" };
    char word2[2][4] = { "a", "bc" };
    arrayStringsAreEqual((char**)word1, 2, (char**)word2, 2);
}

void TestCase_160()
{
    vector<int> nums1, nums2;
    
    ListNode* output = NULL;

    nums1 = { 4,1,8,4,5 };
    nums2 = { 5,6,1,8,4,5 };
    struct ListNode* headA = CreateListNode(nums1);
    struct ListNode* headB = CreateListNode(nums2);
    output = getIntersectionNode(headA, headB);
}

void TestCase_28()
{
    string haystack, needle;
    int expect;

    haystack = "sadbutsad", needle = "sad";
    expect = 0;
    COMPVALUE(expect, strStr(&*haystack.begin(), &*needle.begin()));

    haystack = "leetcode", needle = "leeto";
    expect = -1;
    COMPVALUE(expect, strStr(&*haystack.begin(), &*needle.begin()));
}

void TestCase_1239()
{
    vector<string> arr ;
    int expect;

    arr = { "un","iq","ue" };
    expect = 4;
    COMPVALUE(expect, maxLength((char**)&arr[0][0], (int)arr.size()));

    arr = { "cha","r","act","ers" };
    expect = 6;
    COMPVALUE(expect, maxLength((char**)&arr[0], (int)arr.size()));

    arr = { "abcdefghijklmnopqrstuvwxyz" };
    expect = 26;
    COMPVALUE(expect, maxLength((char**)&arr[0], (int)arr.size()));
}

void TestCase_1832()
{
    string s;
    bool expect;

    s = "thequickbrownfoxjumpsoverthelazydog";
    expect = true;
    COMPVALUE(expect, checkIfPangram(&*s.begin()));

    s = "leetcode";
    expect = false;
    COMPVALUE(expect, checkIfPangram(&*s.begin()));
}

void TestCase_8058()
{
    string s, expect;

    s = "abcdefg";
    printf("%s\r\n", s.c_str());
    reverseLeftWords(&*s.begin(), 2);
    printf("%s\r\n", s.c_str());
    s = "lrloseumgh";
    printf("%s\r\n", s.c_str());
    reverseLeftWords(&*s.begin(), 6);
    printf("%s\r\n", s.c_str());

    s = "abcdefg";
    expect = "cdefgab";
    cout << "expect:" << expect << endl;
    cout << "output:" << reverseLeftWords(s, 2) << endl;

    s = "lrloseumgh";
    expect = "umghlrlose";
    cout << "expect:" << expect << endl;
    cout << "output:" << reverseLeftWords(s, 6) << endl;
}

void TestCase_151()
{
    string s;
    string expect;
    char* output;

    s = "the sky is blue";
    expect = "blue is sky the";
    output = reverseWords((&*s.begin()));
    COMPARRAY((&*expect.begin()), expect.length(), output, strlen(output));
    FREEMEM(output);

    s = "  hello world  ";
    expect = "world hello";
    output = reverseWords((&*s.begin()));
    COMPARRAY((&*expect.begin()), expect.length(), output, strlen(output));
    FREEMEM(output);

    s = "a good   example";
    expect = "example good a";
    output = reverseWords((&*s.begin()));
    COMPARRAY((&*expect.begin()), expect.length(), output, strlen(output));
    FREEMEM(output);
}

void TestCase_541()
{
    string s;
    string expect;

    s = "abcdefg";
    expect = "bacdfeg";

    reverseStr((&*s.begin()), 2);
    COMPARRAY((&*expect.begin()), expect.length(), (&*s.begin()), s.length());

    s = "abcd";
    expect = "bacd";
    reverseStr((&*s.begin()), 2);
    COMPARRAY((&*expect.begin()), expect.length(), (&*s.begin()), s.length());
}

void TestCase_344()
{
    string s;

    s = "hello";
    COUTARRAY((&*s.begin()), s.length());
    reverseString(&*s.begin(), (int)s.length());
    COUTARRAY((&*s.begin()), s.length());
}

void TestCase_1()
{
    vector<int> nums;
    int target;
    vector<int> expect;
    int rSize;
    int* output;

    nums = { 2,7,11,15 };
    target = 9;
    expect = { 0,1 };
    output = twoSum(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 3,2,4};
    target = 6;
    expect = { 1,2 };
    output = twoSum(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 3,3 };
    target = 6;
    expect = { 0, 1};
    output = twoSum(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);
}

void TestCase_202()
{
    bool expect;
    int num;

    num = 19;
    expect = true;
    COMPVALUE(expect, isHappy(num));

    num = 2;
    expect = false;
    COMPVALUE(expect, isHappy(num));
}

void TestCase_350()
{
    vector<int> nums1;
    vector<int> nums2;
    int* output = NULL;
    vector<int> expect;
    int returnsize = 0;

    nums1 = { 1,2,2,1 }, nums2 = { 2,2 };
    expect = { 2,2  };
    output = intersect(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);

    nums1 = { 4,9,5 }, nums2 = { 9,4,9,8,4 };
    expect = { 9 ,4 };
    output = intersect(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);
}

void TestCase_349()
{
    vector<int> nums1;
    vector<int> nums2;
    int* output = NULL;
    vector<int> expect;
    int returnsize = 0;

    nums1 = { 1,2,2,1 }, nums2 = { 2,2 };
    expect = { 2 };
    output = intersection(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);

    nums1 = { 4,9,5 }, nums2 = { 9,4,9,8,4 };
    expect = { 9 ,4 };
    output = intersection(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);
}

void TestCase_383()
{
    string s, t;
    bool expect;

    s = "a";
    t = "b";
    expect = false;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));

    s = "aa";
    t = "ab";
    expect = false;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));

    s = "aa";
    t = "aab";
    expect = true;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));
}

void TestCase_242()
{
    string s, t;
    bool expect;

    s = "anagram";
    t = "nagaram";
    expect = true;
    COMPVALUE(expect, isAnagram(&*s.begin(), &*t.begin()));

    s = "rat";
    t = "cat";
    expect = false;
    COMPVALUE(expect, isAnagram(&*s.begin(), &*t.begin()));
}


void TestCase_20()
{
    string s;
    bool expect;

    s = "()";
    expect = true;
    COMPVALUE(expect, isValid(&*s.begin()));

    s = "()[]{}";
    expect = true;
    COMPVALUE(expect, isValid(&*s.begin()));

    s="(]";
    expect = false;
    COMPVALUE(expect, isValid(&*s.begin()));
}

void TestCase_19()
{
    vector<int> nums = { 1,2,3,4,5 };
    ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = removeNthFromEnd(head, 2);

    nums = { 1 };
    head = CreateListNode(nums);
    output = removeNthFromEnd(head, 1);
}

void TestCase_24()
{
    vector<int> nums = { 1,2,3,4 };
    ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = swapPairs(head);

    nums = { 1 };
    head = CreateListNode(nums);
    output = swapPairs(head);
}


void TestCase_206()
{
    vector<int> nums = { 1,2,3,4,5 };
    ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = reverseList(head);
}

void TestCase_707()
{
    int index = 1;
    int val = 0;
    int param;
    MyLinkedList* obj = myLinkedListCreate();

    myLinkedListAddAtHead(obj, 3);
    myLinkedListAddAtHead(obj, 1);

    myLinkedListAddAtTail(obj, 4);

    myLinkedListAddAtIndex(obj, 1, 2);

    param = myLinkedListGet(obj, 1);

    myLinkedListDeleteAtIndex(obj, 1);

    param = myLinkedListGet(obj, 1);

    myLinkedListFree(obj);
}

void TestCase_203()
{
    vector<int> nums = { 1,2,6,3,4,5,6 };
    int target = 6;
    struct ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = removeElements(head, target);
}

void TestCase_76()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    minWindow(s, t);
    char* output;

    char s0[] = "ADOBECODEBANC";
    char t0[] = "ABC";
    char expect0[] = "BANC";
    output = minWindow(s0, t0);
    COMPSTRING(expect0, output);
    //FREEMEM(output);

    char s1[] = "a";
    char t1[] = "a";
    char expect1[] = "a";
    output = minWindow(s1, t1);
    COMPSTRING(expect1, output);
    //FREEMEM(output);


    char s2[] = "a";
    char t2[] = "aa";
    char expect2[] = "";
    output = minWindow(s2, t2);
    COMPSTRING(expect2, output);
    //FREEMEM(output);
}

void TestCase_904()
{
    vector<int> nums;
    int expect;

    nums = { 0, 1, 6, 6, 4, 4, 6 };
    expect = 5;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 1, 0, 1, 4, 1, 4, 1, 2, 3 };
    expect = 5;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    expect = 5;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 1,2,1 };
    expect = 3;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 0,1,2,2 };
    expect = 3;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 1,2,3,2,2 };
    expect = 4;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));
}

void TestCase_209()
{
    vector<int> nums;
    int target;
    int expect;

    nums = { 2,3,1,2,4,3 };
    target = 7;
    expect = 2;
    COMPVALUE(expect, minSubArrayLen(target, nums.data(), (int)nums.size()));

    nums = { 1,4,4 };
    target = 4;
    expect = 1;
    COMPVALUE(expect, minSubArrayLen(target, nums.data(), (int)nums.size()));

    nums = { 1,1,1,1,1,1,1,1 };
    target = 11;
    expect = 0;
    COMPVALUE(expect, minSubArrayLen(target, nums.data(), (int)nums.size()));
}

void TestCase_977()
{
    vector<int> nums;
    vector<int> expect;
    int * output;
    int retsize = 0;

    nums = { -4,-1,0,3,10 };
    expect = { 0,1,9,16,100 };
    COUTARRAY(expect.data(), expect.size());
    output = sortedSquares(nums.data(), (int)nums.size(), &retsize);
    COUTARRAY(output, retsize);
    FREEMEM(output);

    nums = { -7,-3,2,3,11 };
    expect = { 4,9,9,49,121 };
    COUTARRAY(expect.data(), expect.size());
    output = sortedSquares(nums.data(), (int)nums.size(), &retsize);
    COUTARRAY(output, retsize);
    FREEMEM(output);
}

void TestCase_844()
{
    bool expect;
    string s, t;

    s = "bxj##tw";
    t = "bxo#j##tw";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s, t));

    s = "ab#c";
    t = "ad#c";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s, t));
        
    char s0[] = "rheyggodcclgstf";
    char t0[] = "#rheyggodcclgstf";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s0, t0));

    char s1[] = "ab#c";
    char t1[] = "ad#c";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s1, t1));

    char s2[] = "ab##";
    char t2[] = "c#d#";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s2, t2));

    char s3[] = "a#c";
    char t3[] = "b";
    expect = false;
    COMPVALUE(expect, backspaceCompare(s3, t3));
}

void TestCase_283()
{
    vector<int> nums;

    nums = { 0,1,0,3,12 };
    COUTARRAY(nums.data(), nums.size());
    moveZeroes(nums.data(), (int)nums.size());
    COUTARRAY(nums.data(), nums.size());

    nums = { 0 };
    COUTARRAY(nums.data(), nums.size());
    moveZeroes(nums.data(), (int)nums.size());
    COUTARRAY(nums.data(), nums.size());
}

void TestCase_26()
{
    vector<int> nums;
    int expect;

    nums = { 1,1,2 };
    expect = 2;
    COMPVALUE(expect, removeDuplicates(nums.data(), (int)nums.size()));

    nums = { 1 };
    expect = 1;
    COMPVALUE(expect, removeDuplicates(nums.data(), (int)nums.size()));

    nums = { 0,0,1,1,1,2,2,3,3,4 };
    expect = 5;
    COMPVALUE(expect, removeDuplicates(nums.data(), (int)nums.size()));
}

void TestCase_27()
{
    vector<int> nums;
    int value;
    int expect;

    nums = { 3,2,2,3 };
    value = 3;
    expect = 2;
    COMPVALUE(expect, removeElement(nums.data(), (int)nums.size(), value));

    nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    value = 2;
    expect = 5;
    COMPVALUE(expect, removeElement(nums.data(), (int)nums.size(), value));
}

void TestCase_367()
{
    COMPVALUE(true, isPerfectSquare(1));
    COMPVALUE(true, isPerfectSquare(16));
    COMPVALUE(false, isPerfectSquare(14));
}

void TestCase_69()
{
    COMPVALUE(6, mySqrt(36));
    COMPVALUE(1, mySqrt(1));
    COMPVALUE(1, mySqrt(3));
    COMPVALUE(2, mySqrt(8));
    COMPVALUE(2, mySqrt(4));
}

void TestCase_35()
{
    vector<int> nums;
    int target;
    int expect;

    nums = { 1,3,5,6 };
    target = 5;
    expect = 2;
    COMPVALUE(expect, searchInsert(nums.data(), (int)nums.size(), target));

    nums = { 1,3,5,6 };
    target = 2;
    expect = 1;
    COMPVALUE(expect, searchInsert(nums.data(), (int)nums.size(), target));

    nums = { 1,3,5,6 };
    target = 7;
    expect = 4;
    COMPVALUE(expect, searchInsert(nums.data(), (int)nums.size(), target));
}

void TestCase_34()
{
    vector<int> nums;
    int target;
    vector<int> expect;
    int* output;
    vector<int> output2;
    int retsize = 0;

    nums = { 1};
    target = 1;
    output2 = searchRange(nums, target);

    nums = { 5,7,7,8,8,10 };
    target = 8;
    expect = { 3, 4 };
    output2 = searchRange(nums, target);
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    FREEMEM(output);

    nums = { 5,7,7,8,8,10 };
    target = 6;
    expect = { -1, -1 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    FREEMEM(output);

    nums = {  };
    target = 0;
    expect = { -1, -1 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    FREEMEM(output);
}

void TestCase_704()
{
    vector<int> nums;
    int target;
    int expect;

    nums = { -1, 0, 3, 5, 9, 12 };
    target = 9;
    expect = 4;
    COMPVALUE(expect, search(nums.data(), (int)nums.size(), target));

    nums = { -1,0,3,5,9,12 };
    target = 2;
    expect = -1;
    COMPVALUE(expect, search(nums.data(), (int)nums.size(), target));
}


funcTest getFuncTestPointer(int caseno)
{
    for (int i = 0; i < sizeof(g_tFuncName) / sizeof(FUNCNAME); i++)
    {
        if (g_tFuncName[i].caseno == caseno)
            return g_tFuncName[i].funcName;
    }

    return NULL;
}

//#define CallCase(num) TestCase_##num()

void TestCase(unsigned int caseno)
{
    cout << "Run TestCase: " << caseno << "." << endl;
    funcTest func;
    func = getFuncTestPointer(caseno);
    if (!func) {
        cout << "Problem " << caseno << " to be continue..." << endl;
        return;
    }

    func();
}

