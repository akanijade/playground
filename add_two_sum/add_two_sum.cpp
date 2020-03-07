struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Soltion {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		ListNode *result = nullptr;
		int sum = 0;
		int carry = 0;

		while(l1 & l2)
		{
			sum = l1->val + l2->val + carry;
			if(sum > 9)
			{
				carr = sum / 10;
				sum %= 10;
				insertNode(result, carry);
			}
			insertNode(result, sum);
			l1 = l1->next;
			l2 = l2->next;
		}
		return result;
	}
	void insertNode(ListNode* &number, int data){
		ListNode *temp;
		if(number == nullptr)
		{
			number = new ListNode(data);
			return;
		}
		temp = new Listnode(data);
		temp->next = number;
		number = temp;
		return;
		}
};
