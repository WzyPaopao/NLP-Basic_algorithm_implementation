#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LETTER_BASE 97

typedef struct Node {
	struct Node* letters[26];
	int num;
	char parent;

	Node () {
		for (int i = 0; i < 26; i++) {
			letters[i] = NULL;
		}
		num = 0;
		parent = '!';
	}
}Node, *p_Node;

void insertTrie(p_Node node, char* pat, int i) {
	int len = strlen(pat);
	
	if (i != -1) {
		node->parent = pat[i];
	}
	i++;
	int c = pat[i] - LETTER_BASE;
	
	if ( i == len ) {
		node->num ++;
		return;
	}
	
	// 第一次使用该该节点的该字母
	if ( !(node->letters[c]) ) {
		node->letters[c] = new Node();
	}
	
	// 递归插入
	if (i < len) {
		insertTrie(node->letters[c], pat, i);
	}
	
	return; 
}

int search (p_Node node, char* pat, int i) {
	int len = strlen(pat);
	i++;
	int c = pat[i]-LETTER_BASE;
	
	if ( (i == len) && (node->num != 0)) {
		return node->num;
	}
	// 查询失败
	if ( !(node->letters[c]) ) {
		return -1;
	}
	
	int res = search(node->letters[c], pat, i);
	return res;
}

int main() {
	printf("hello world\n");
	p_Node root = new Node();
	insertTrie(root, "his", -1);
	insertTrie(root, "hi", -1);
	insertTrie(root, "his", -1);
	insertTrie(root, "he", -1);
	insertTrie(root, "she", -1);
	insertTrie(root, "her", -1);
	insertTrie(root, "shy", -1);
	
	int res = search(root, "shy", -1);
	printf("%d\n", res);
	
	return 0;
}
