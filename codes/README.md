# Codes Directory Guide

这个目录采用“来源主归档 + 知识点索引”的分类方式。

## 目录职责

| 目录 | 定位 |
| --- | --- |
| [`-0x10_model`](./-0x10_model/) | 不够稳定但有复用价值的模型写法。 |
| [`-0x20_misc`](./-0x20_misc/) | 资料、零散记录和非标准题目代码。 |
| [`-0x30_competition`](./-0x30_competition/) | 平台题、比赛题和补题代码的唯一主归档。 |
| [`-0x40_template`](./-0x40_template/) | 接口清楚、可直接复制的稳定模板。 |
| [`0x00` - `0x90`](./0x00_basic_algorithm/) | 基础算法、数据结构、数学、图论、字符串等知识点索引。 |
| [`0xA0_misc`](./0xA0_misc/) | 题解、翻译、作业和其他杂项内容。 |
| [`0xB0_conclution`](./0xB0_conclution/) | 总结和阶段性复盘。 |
| [`0xC0_suepacm`](./0xC0_suepacm/) | SUEP ACM 相关训练、比赛和日常资料。 |

## 归档规则

| 内容 | 主位置 | 说明 |
| --- | --- | --- |
| 平台题、比赛题、补题代码 | [`-0x30_competition`](./-0x30_competition/) | 按平台或比赛来源归档，作为唯一代码副本。 |
| Codeforces 题 | [`-0x30_competition/-0x33_codeforces`](./-0x30_competition/-0x33_codeforces/) | 比赛目录使用官方 `contestId`，文件名使用 `cf<contestId><problemId>.<suffix>`。 |
| AtCoder / NowCoder / Luogu 等平台题 | 对应平台目录 | 尽量使用平台简称 + 官方编号。 |
| XCPC、训练赛、校赛 | [`-0x30_competition/-0x39_xcpc`](./-0x30_competition/-0x39_xcpc/) 或 [`-0x30_competition/-0x3F_misc`](./-0x30_competition/-0x3F_misc/) | 有明确系列时放系列目录，临时训练放 misc。 |
| 模板 | [`-0x40_template`](./-0x40_template/) | 要求接口清楚、可直接复制。 |
| 模型代码 | [`-0x10_model`](./-0x10_model/) | 用于沉淀技巧，允许不如模板稳定。 |
| 题解、总结、翻译 | [`0xA0_misc`](./0xA0_misc/) 或 [`0xB0_conclution`](./0xB0_conclution/) | 不作为题目代码主归档。 |

## 知识点目录的定位

`0x00_basic_algorithm`、`0x10_data_structure`、`0x50_dynamic_programming` 这类目录作为 topic index 使用，负责组织复习路径和知识点入口。

这种方式避免同一道题因为“树上 DP / 线段树 / 贪心”这种多标签属性被重复存放。来源目录负责保存唯一代码，知识点目录负责复习路径。

## 当前整理状态

已按文件名前缀迁移可自动识别来源的历史题目代码，包括 `cf*`、`lc*`、`lgp*`、`ac*`、`lq*`、`nc*`、`abc*`、`sp*`、`lb*`，以及带明确 Codeforces 题号、`cfedu`、`uva`、`lgb/lgt`、`USACO` 标记的文件。百度之星历史目录也已并入 [`-0x30_competition/-0x3B_baidustar`](./-0x30_competition/-0x3B_baidustar/)。

知识点目录中剩余的源码主要是模板草稿、模型代码、课程作业、校内训练、Project Euler 或无法从文件名稳定判断来源的历史文件；这些文件不再强行自动迁移。

## 兜底目录

`misc` 目录只用于短期或无法稳定归类的内容。能确定来源的题目不要长期放在 misc；能抽成模板的代码不要长期放在 model 或 topic 目录。
