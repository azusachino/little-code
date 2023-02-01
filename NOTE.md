# Other Note

## 常用 Trick

### 二分查找

- when you want to find an specific target element you use lo <= hi.
- When you want to find an element which is not specific element you use `lo < hi`.
- mid = lo + (hi - lo) / 2 rather than mid = (hi + lo) / 2 => 防止 lo+hi 大于 Integer.MAX_VALUE 导致 overflow

### 快慢指针找中点

```cpp
ListNode *p1 = head, *p2 = head;
while(p2 && p2->next){
     p1 = p1->next;
     p2 = p2->next->next;
}
```

## Local Preview

Run `mdbook serve` to preview.

### Prerequisite

`cargo install mdbook`

## Build to Nginx

`mdbook build --dest-dir /usr/share/nginx/html/`

## VSCode Usage Problem

### Please update includePath?

After long time searching, figured out the problem was `configurationProvider` wrong. Remove this or use `ms-vscode.cpp-tools` instead.