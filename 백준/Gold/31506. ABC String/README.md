# [Gold I] ABC String - 31506 

[문제 링크](https://www.acmicpc.net/problem/31506) 

### 성능 요약

메모리: 32704 KB, 시간: 200 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 9월 4일 13:47:44

### 문제 설명

<p>You're given a string consisting of the characters <code>A</code>, <code>B</code>, and <code>C</code>. The string contains the same count of <code>A</code>, <code>B</code>, and <code>C</code> characters.</p>

<p>A string is <em>beautiful</em> if</p>

<ul>
	<li>Its length is divisible by $3$.</li>
	<li>The string can be split evenly into contiguous substrings of size $3$, where each substring has one <code>A</code>, one <code>B</code>, and one <code>C</code>, in any order.</li>
</ul>

<p>For example: <code>ABCCBA</code> is a beautiful string, but <code>ABCAB</code> and <code>CCBAAB</code> are not beautiful.</p>

<p>Given a string, you want to partition it into subsequences (not necessarily contiguous) such that each subsequence is a beautiful string.</p>

<p>For example, for the string <code>ABACBCAACCBB</code>, we can do the following:</p>

<pre>AB   CA C B
  ACB  A C B</pre>

<p>This partitions the string into two subsequences <code>ABCACB</code> and <code>ACBACB</code>, both of which are beautiful strings.</p>

<p>For the given string, find the minimum number of subsequences you can partition it into such that each subsequence is beautiful. It can be proven that there is always at least one such partition for all possible inputs that satisfy the input constraints.</p>

### 입력 

 <p>The first line of input contains a string $s$ ($3 \le |s| \le 3 \cdot 10^5$). $|s|$ is divisible by $3$. $s$ contains an equal number of characters <code>A</code>, <code>B</code>, and <code>C</code>.</p>

### 출력 

 <p>Output a single integer, which is the minimum subsequences that $s$ can be partitioned into so each subsequence is a beautiful string.</p>

