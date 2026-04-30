# Codes Directory Guide

这个目录采用“来源主归档 + 知识点索引”的分类方式。

## 主规则

1. 题目代码的唯一主归档按来源放在 [`-0x30_competition`](./-0x30_competition/)。
2. 知识点目录 `0x00` 到 `0x90` 作为复习索引和历史分类入口，不再作为新题代码的默认落点。
3. 稳定可复制的模板放在 [`-0x40_template`](./-0x40_template/)。
4. 不够稳定但有复用价值的模型写法放在 [`-0x10_model`](./-0x10_model/)。
5. 资料、作业、翻译、复盘等非标准题目代码放在 misc / notes 类目录。

## 新代码放置规则

| 内容 | 主位置 | 说明 |
| --- | --- | --- |
| 平台题、比赛题、补题代码 | [`-0x30_competition`](./-0x30_competition/) | 按平台或比赛来源归档。 |
| Codeforces 题 | [`-0x30_competition/-0x33_codeforces`](./-0x30_competition/-0x33_codeforces/) | 比赛目录使用官方 `contestId`，文件名使用 `cf<contestId><problemId>.<suffix>`。 |
| AtCoder / NowCoder / Luogu 等平台题 | 对应平台目录 | 尽量使用平台简称 + 官方编号。 |
| XCPC、训练赛、校赛 | [`-0x30_competition/-0x39_xcpc`](./-0x30_competition/-0x39_xcpc/) 或 [`-0x30_competition/-0x3F_misc`](./-0x30_competition/-0x3F_misc/) | 有明确系列时放系列目录，临时训练放 misc。 |
| 模板 | [`-0x40_template`](./-0x40_template/) | 要求接口清楚、可直接复制。 |
| 模型代码 | [`-0x10_model`](./-0x10_model/) | 用于沉淀技巧，允许不如模板稳定。 |
| 题解、总结、翻译 | [`0xA0_misc`](./0xA0_misc/) 或 [`0xB0_conclution`](./0xB0_conclution/) | 不作为题目代码主归档。 |

## 知识点目录的定位

`0x00_basic_algorithm`、`0x10_data_structure`、`0x50_dynamic_programming` 这类目录保留为 topic index。历史代码可以暂时留在原处；后续整理时，如果某个文件已经能明确追溯到平台或比赛，应迁移到来源目录，并在对应知识点 README 中保留链接或题单记录。

这种方式避免同一道题因为“树上 DP / 线段树 / 贪心”这种多标签属性被重复存放。来源目录负责保存唯一代码，知识点目录负责复习路径。

## 历史文件迁移流程

整理旧知识点目录时按这个顺序处理：

1. 先确认题目来源和官方编号。
2. 把代码移动到 [`-0x30_competition`](./-0x30_competition/) 下的来源目录。
3. 文件名改成平台统一格式，例如 `cf2226A.cpp`、`lgp3372.cpp`。
4. 在原知识点 README 或题单中保留链接，而不是复制第二份代码。
5. 如果同题已有多个版本，只保留必要版本；备注写进文件名后缀或题单。

## 兜底目录约束

`misc` 目录只用于短期或无法稳定归类的内容。能确定来源的题目不要长期放在 misc；能抽成模板的代码不要长期放在 model 或 topic 目录。
