/// <文件名> SystemConstantDefine.h </文件名>
/// <描  述>
///         定义整个系统的常量
/// </描 述>
/// <作  者> zhy </作者>
/// <创建日期> 2023-12-04 </创建日期>

#pragma once

namespace SystemConstant
{

    //系统的工作模式，分2种：工作模式，用户不能查看逻辑组件
    //                    编辑模式，可以进行逻辑组件的编辑
    enum Mode
    {
        WorkMode = 0, //工作模式
        EditMode = 1, //编辑模式
    };
}
