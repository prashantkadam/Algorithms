import java.io.*;
import java.util.*;
class minimumResult{
	int k;
	float minimum;
}
class Tree_Node
{
	String word;
	Tree_Node left;
	Tree_Node right;
}
public class Submission {

public static int opt_search_tree(int n,float[] p, int[][] R) {
int i,j,diagonal;
float[][] A = new float[n+1][n+1];
for (i = 0; i <= n; i++) {
	A[i][i] = 0;
	R[i][i] = 0;
	if(i<n){
		A[i][i+1] = p[i];
		R[i][i+1] = i+1;
	}
}
for (diagonal = 2; diagonal <= n; diagonal++) {
	for (i = 0; i <= n - diagonal; i++) {
		j = i + diagonal;
		minimumResult mr = minimum(i,j,A);
		A[i][j] = mr.minimum  + sum(i,j,p);
		R[i][j] = mr.k + 1;
	}	
}
return R[0][n];
}
public static float sum(int i, int j, float[] p) {
	float sum = 0;
	for (int k = i; k < j; k++) {
		sum = sum + p[k];
	}
	return sum;
}
private static minimumResult minimum(int i, int j, float[][] a) {
	minimumResult mr = new minimumResult();
	float min = 99999999.0f;
	int minIndex = 0;
	for (int k	= i; k < j; k++) {
		if(a[i][k] + a[k + 1][j] < min)
		{
			min = a[i][k] + a[k + 1][j];
			minIndex = k;
		}
	}	
	mr.k = minIndex;
	mr.minimum = min;
	return mr;
}
public static Tree_Node tree(int i,int j,int[][] R,String[] words)
{
	if(R[i][j]==0)
		return null;
	else
	{
		Tree_Node treenode = new Tree_Node();
		treenode.word = words[R[i][j]-1];
		treenode.left = tree(i,R[i][j]-1,R,words);
		treenode.right = tree(R[i][j] ,j,R,words);
		return treenode;
	}
}

public static void readInput(float[] p1,String[] words,String[] wordsCopy,String fileName)
{
	FileInputStream inputstream = null;
	BufferedReader br =null;
	DataInputStream in = null;
	try {
		inputstream = new FileInputStream(fileName);
		in = new DataInputStream(inputstream);
		br = new BufferedReader(new InputStreamReader(in));
		String s;
		int i = 0;
		while ((s = br.readLine()) != null) {
			String[] splited=s.split(" ");
			p1[i] = Float.parseFloat(splited[1]);
			words[i] = splited[0];
			wordsCopy[i] = splited[0];
			i++;
		}
		in.close();
		inputstream.close();
	}catch(IOException ex){
		
	}catch (Exception e) {
		}
	}

public static void main(String args[]) {
	//example 1 with n = 4

	int n = 4;
	int[][] R = new int[n+1][n+1];
	float[] P = new float[4];
	String[] wordsexample1 = new String[4];
	String[] wordsexample1copy = new String[4];
	readInput(P, wordsexample1, wordsexample1copy,"input1.txt");
	int rootIndex = opt_search_tree(n,P,R);
	int i=0;
	int j=n;
	Tree_Node head = tree(i,j,R,wordsexample1);
	StringBuilder sb = new StringBuilder();
	sb.append("\"" + head.word + "\" is root of optimal binary search tree\n");
	printTree(head,sb);
	writeToFile(sb,"output1.txt");
	System.out.println("-------------------------- Example 1 output --------------------------\n");
	System.out.println(sb.toString());
	sb.delete(0, sb.length());
	//example 2 with n = 10
	n=10;
	int[][] R1 = new int[n+1][n+1];
	float[] p1Copy= {0,0,0,0,0,0,0,0,0,0};
	String[] wordsexample2 = new String[10];
	String[] wordsexample2copy = new String[10];
	float[] P1 = new float[10];
	readInput(P1, wordsexample2, wordsexample2copy,"input2.txt");
	Arrays.sort(wordsexample2);
	int ix=0;
	for (String s : wordsexample2) {
		int index = Arrays.asList(wordsexample2copy).indexOf(s);// s.toString());	
		p1Copy[ix] = P1[index];
		ix++;
	}
	int rootIndex1 = opt_search_tree(n,p1Copy,R1);
	int i1=0;
	int j1=n;
	Tree_Node head1 = tree(i1,j1,R1,wordsexample2);
	sb.append("\"" + head1.word + "\" is root of optimal binary search tree\n");
	printTree(head1,sb);
	writeToFile(sb,"output2.txt");
	System.out.println("-------------------------- Example 2 output --------------------------\n");
	System.out.println(sb.toString());
}
private static void writeToFile(StringBuilder sb,String fileName) {
	
	try {
		FileWriter fw = new FileWriter(fileName,false);
		PrintWriter pw = new PrintWriter(fw);
		pw.println(sb);
		fw.close();
	} catch (IOException e) {
		e.printStackTrace();
	}
}
public static void printTree(Tree_Node head,StringBuilder sb) {
	if (head.left == null && head.right == null)
		return;
	Tree_Node t_left = head.left;
	Tree_Node t_right = head.right;
	if(t_left != null)
		sb.append("\""+ t_left.word+"\""+" is left child of "+ "\""+ head.word+"\"\n");
	if(head.left != null)
		printTree(head.left,sb);
	if(t_right != null)
		sb.append("\""+ t_right.word+"\""+" is right child of "+ "\""+ head.word+"\"\n");
	if(head.right != null)
		printTree(head.right,sb);
	}
}