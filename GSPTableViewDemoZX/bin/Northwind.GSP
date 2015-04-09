<?xml version="1.0" encoding="utf-8" ?>
<GSPModel GSPModelNode="True" DataFormatVersion="2.5.12" BizVersion="" xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">
    <a:Version>2.5.12</a:Version>
    <a:Name>GSPModel</a:Name>
    <a:Mode>2</a:Mode>
    <c:Databases>
        <o:Database>
            <a:Name>DB</a:Name>
            <c:Tables>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>GYS</a:Name>
                        <a:DisplayName>供应商</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>GYSID</a:FieldName>
                                <a:DisplayName>供应商ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>GSM</a:FieldName>
                                <a:DisplayName>公司名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:TrimSpace>False</a:TrimSpace>
                                <a:CaseSensitive>True</a:CaseSensitive>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LXRXM</a:FieldName>
                                <a:DisplayName>联系人姓名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LXRTX</a:FieldName>
                                <a:DisplayName>联系人头衔</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>GHZJE</a:FieldName>
                                <a:DisplayName>供货总金额</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>CP.SCZJ[GYSID=?GYSID].SUM</a:CalcExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAFtj0sOwjAMRB+F8hOHCqqAVSkSG8Su/KKqRaAK9hyHY3GTMPGCRYVHzmfs8SQhhDBLE959GAA9QTFWLik5cubATahhKnLPU2QtulUhrh6kJWNBoT3GK3ck8TBUrkzuadRtFhvN9fHSlVE445hIllPJqJV4q7zwgJHotcQniRuh/DNi58yDVL1z7sLPN7OH6B9d38/VfQGFRSD1                        </o:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>DDMX</a:Name>
                        <a:DisplayName>订单明细</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <a:RowRefEnable>True</a:RowRefEnable>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>DDMXID</a:FieldName>
                                <a:DisplayName>订单明细ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>DDID</a:FieldName>
                                <a:DisplayName>订单ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:MasterTableName>DD</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>CPID</a:FieldName>
                                <a:DisplayName>产品ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:MasterTableName>CP</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>DJ</a:FieldName>
                                <a:DisplayName>单价</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>SL</a:FieldName>
                                <a:DisplayName>数量</a:DisplayName>
                                <a:DataType>7</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>DDMXZJ</a:FieldName>
                                <a:DisplayName>订单明细总价</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>DJ*SL</a:CalcExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAFdkC0WwkAMhKeFQh8gEAgEAoFGoWEEAo3gBBykx+EYHKk3WPKzWfY1Ip0m32Y2m1JKm67FZwasADSWsRSJuaYcnIotsdbalNwFec7i+6RDC8UbTR4HTsTwIHqtGdnmrnzKTDAXT/RJnf5XpNzK4xiC9L6RsmSJAPoQe8L6dsXqnuLlMd6ykIq9jRlX7oVEHLkQf+PK/RpAuA8v+to2uHr5e5BltTd/KogTVg==                        </o:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>DD</a:Name>
                        <a:DisplayName>订单</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>DDID</a:FieldName>
                                <a:DisplayName>订单ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>KHID</a:FieldName>
                                <a:DisplayName>客户ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:MasterTableName>KH</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>GYID</a:FieldName>
                                <a:DisplayName>雇员ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:MasterTableName>GY</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>DQDDZJ</a:FieldName>
                                <a:DisplayName>当前订单总价</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>2</a:Precision>
                                <a:IgnoreZero>True</a:IgnoreZero>
                                <a:CalcExpr>DDMX.DDMXZJ[DDID =?DDID].SUM</a:CalcExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAFtj8sNgzAQRF8IJAFRBiVQwEqcc4qUCiiEciiDzhxm+JhDvJLn4/VoN6WU2qpgvkMD3NYyHJcUdEEh9KOZFPTB+nH3zaSYvkEp4lYzKRiDSpjDpGAIHkJH5P7pHTzl28r5yyd4/fFl1afvYaV8tN2Wf5kffrKyCqM=                        </o:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>CP</a:Name>
                        <a:DisplayName>产品</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>CPID</a:FieldName>
                                <a:DisplayName>产品ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>GYSID</a:FieldName>
                                <a:DisplayName>供应商ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:MasterTableName>GYS</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>CPMC</a:FieldName>
                                <a:DisplayName>产品名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>LBID</a:FieldName>
                                <a:DisplayName>类别ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:MasterTableName>LB</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>SCZJ</a:FieldName>
                                <a:DisplayName>售出总价</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>DDMX.DDMXZJ[CPID=?CPID].SUM</a:CalcExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>SCZL</a:FieldName>
                                <a:DisplayName>售出总量</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>DDMX.SL[CPID=?CPID].SUM</a:CalcExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>SCPJJ</a:FieldName>
                                <a:DisplayName>售出平均价</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>5</a:Precision>
                                <a:CalcExpr>SCZJ/SCZL</a:CalcExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAH7////fx5WJoYVzAwMLAwMDIxACKaABIjvxuDI4MzgysAAlIeCBl8HKEsBymiQdWBgAomBCXYgw5EhjyGFoYghnyETSEPMBClgYPB3AFMMDBoODFuexnStXiXiADEcbANIcziDJ4MfgwuDP5AVjKI5AqZZAsYwcAA7E0KwATVnMgQwZADtzWNIhboHKMjA8CDXAUwzMJg6MHReuveA+7CaAwByShxp                        </o:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>KH</a:Name>
                        <a:DisplayName>客户</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>KHID</a:FieldName>
                                <a:DisplayName>客户ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>GSMC</a:FieldName>
                                <a:DisplayName>公司名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LXRXM</a:FieldName>
                                <a:DisplayName>联系人姓名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LXRTX</a:FieldName>
                                <a:DisplayName>联系人头衔</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>DZ</a:FieldName>
                                <a:DisplayName>地址</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>CS</a:FieldName>
                                <a:DisplayName>城市</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>DQ</a:FieldName>
                                <a:DisplayName>地区</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>DDSL</a:FieldName>
                                <a:DisplayName>订单数量</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>DD.DDID[KHID = ?KHID].COUNT</a:CalcExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>DDZJ</a:FieldName>
                                <a:DisplayName>订单总价</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>DD.DQDDZJ[KHID = ?KHID].SUM</a:CalcExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAH7////fx5WJoYVzAwMLAwMDIxACARAHkNO4I9gQwhzUbR5EpTpzODK4M/AwARU4Mzgx8DJCVIOBBwOYIqBIc4BLAk3wghhBJTpzBACMyKUwRthBAPUiAMZDmDdcCOMEUZAmc5AA6CuwGpEg68D2DtwI0wQRkCZzgxuMCO8GAIQroB55ECwAwDlmyCh                        </o:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>LB</a:Name>
                        <a:DisplayName>类别</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>LBID</a:FieldName>
                                <a:DisplayName>类别ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LB</a:FieldName>
                                <a:DisplayName>类别</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAH7////fx5WJoYVzAwMQMTACIRAwATE+f3f/MAMMJFTAeSBVIB5D/3zEwB7TAs0                        </o:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>GY</a:Name>
                        <a:DisplayName>雇员</a:DisplayName>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>GYID</a:FieldName>
                                <a:DisplayName>雇员ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>XS</a:FieldName>
                                <a:DisplayName>姓氏</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>MZ</a:FieldName>
                                <a:DisplayName>名字</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>TX</a:FieldName>
                                <a:DisplayName>头衔</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>XSE</a:FieldName>
                                <a:DisplayName>销售额</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:CalcExpr>DD.DQDDZJ[GYID=?GYID].SUM</a:CalcExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <a:CompressData>True</a:CompressData>
                        <o:Records>eAH7////fx5WJoYVzAwMrAwMDIxACKYYGBTiwWxOPwagHIMzgyuDP0gKBDwcGJhANEitXzqYuh0GVRaCUGbiABYDy3cXg6kpENOexnJXccSBjGBgUEh1YGABMUCmlfaCqdxAiAVT9UJBMgwMCdkOYPeBZXNmgSlmP7Ciu/6MuRBFQBIAp5kWAg==                        </o:Records>
                    </o:TableData>
                </o:Table>
            </c:Tables>
        </o:Database>
    </c:Databases>
</GSPModel>
