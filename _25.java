package swordoffer;

import java.util.Iterator;
import java.util.Scanner;
import java.util.Stack;

import org.junit.Test;

/**
 * 题目：列出二叉树的路径和为某个值的所有路径
 */
public class _25 {

	class Node{
		int data;
		Node lc;
		Node rc;
	}
	
	void findPath(Node tree,int sum){
		if(tree == null)
			return;
		Stack<Integer> path = new Stack<>();
		int currentsum = 0;
		findPath(tree,sum,currentsum,path);
	}
	private void findPath(Node tree, int sum, int currentsum,
			Stack<Integer> path) {
		currentsum = currentsum + tree.data;
		boolean isLeaf = tree.lc == null && tree.rc == null;
		path.push(tree.data);
		if(isLeaf && currentsum == sum){
			System.out.println("FIND THE PATH");
			for(Iterator<Integer> it = path.iterator();it.hasNext();){
				System.out.print(it.next()+"  -->  ");
			}
			System.out.println();
		}
		if(tree.lc != null)
			findPath(tree.lc,sum,currentsum,path);
		if(tree.rc != null)
			findPath(tree.rc, sum, currentsum, path);
		currentsum = currentsum - tree.data;
		path.pop();
	}
	
	Node  create(Scanner in){
		Node node = null;
		if(in.hasNext()){
			int data = in.nextInt();
			if(data == 0)
				return node;
			else{
				node = new Node();
				node.data = data;
				node.lc = create(in);
				node.rc = create(in);
			}
		}
		return node;
	}
	
	//前序遍历
	void preTrave(Node node){
		if(node == null)
			return;
		System.out.print(node.data+"-->");
		preTrave(node.lc);
		preTrave(node.rc);
	}
	
	@Test
	public void test1() throws Exception {
		Scanner in = new Scanner(System.in);
		Node node = create(in);
		preTrave(node);
		findPath(node,22);
		
	}
	
	
	
	
	
	
	
	
	
	
}
