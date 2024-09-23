class PointerSequenceList<T> {
    // 定义链表的节点类
    private class Node {
        T data;
        Node next;

        public Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;
    private int size;

    public PointerSequenceList() {
        head = null;
        size = 0;
    }

    public void clear() {
        head = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int length() {
        return size;
    }

    public T get(int i) throws Exception {
        if (i < 0 || i >= size) {
            throw new Exception("索引超出范围");
        }
        Node current = head;
        for (int index = 0; index < i; index++) {
            current = current.next;
        }
        return current.data;
    }

    public void insert(int i, T x) throws Exception {
        if (i < 0 || i > size) {
            throw new Exception("索引超出范围");
        }
        Node newNode = new Node(x);
        if (i == 0) {
            newNode.next = head;
            head = newNode;
        } else {
            Node prev = head;
            for (int index = 0; index < i - 1; index++) {
                prev = prev.next;
            }
            newNode.next = prev.next;
            prev.next = newNode;
        }
        size++;
    }

    public void remove(int i) throws Exception {
        if (i < 0 || i >= size) {
            throw new Exception("索引超出范围");
        }
        if (i == 0) {
            head = head.next;
        } else {
            Node prev = head;
            for (int index = 0; index < i - 1; index++) {
                prev = prev.next;
            }
            prev.next = prev.next.next;
        }
        size--;
    }

    public int indexOf(T x) {
        Node current = head;
        for (int index = 0; index < size; index++) {
            if (current.data.equals(x)) {
                return index;
            }
            current = current.next;
        }
        return -1;
    }

    public void reverse() {
        if (size <= 1) {
            return; 
        }
        Node prev = null;
        Node current = head;
        while (current != null) {
            Node nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    public void display() {
        Node current = head;
        System.out.print("[");
        while (current != null) {
            System.out.print(current.data);
            current = current.next;
            if (current != null) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            PointerSequenceList<Integer> list = new PointerSequenceList<>();
            list.insert(0, 10);
            list.insert(1, 20);
            list.insert(2, 30);
            list.display();

            list.remove(1);
            list.display();

            System.out.println("第 1 个元素是: " + list.get(1));

            System.out.println("20 的索引是: " + list.indexOf(20));

            list.reverse();
            list.display();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}