<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>">
<title>选择内容</title>
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript">
//获得选中文件的文件名
function getCheckboxItem()
{
	var allSel="";
	if(document.form2.arcID.value) return document.form2.arcID.value;
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(document.form2.arcID[i].checked)
		{
			if(allSel=="")
				allSel = document.form2.arcID[i].value;
			else
				allSel = allSel+","+document.form2.arcID[i].value;
		}
	}
	return allSel;	
}
function selAll()
{
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(!document.form2.arcID[i].checked)
		{
			document.form2.arcID[i].checked=true;
		}
	}
}
function noSelAll()
{
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(document.form2.arcID[i].checked)
		{
			document.form2.arcID[i].checked=false;
		}
	}
}
function ReturnValue()
{
	if(window.opener.document.<?php echo $f?>.value==""){
		window.opener.document.<?php echo $f?>.value = getCheckboxItem();
	}
	else{
		window.opener.document.<?php echo $f?>.value += ","+getCheckboxItem();
	}
	window.opener=null;
  window.close();
}
</script>
</head>
<body leftmargin="0" topmargin="0" background='images/allbg.gif'>
<table width='98%' border='0' align='center' cellpadding='0' cellspacing='0' align="center">
<tr> 
<td align='center' valign='top'>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
<tr bgcolor="#FFFFFF"><td height="4"></td></tr>
</table>
<table width="100%" border="0" cellpadding="2" cellspacing="1" bgcolor="#D6D6D6">
<tr bgcolor="#E7E7E7"> 
<td height="24" colspan="9" background="images/tbg.gif">
<strong> §内容列表</strong>
</td>
</tr>
<form name="form2">
<tr align="center" bgcolor="#FAFAF1" height="22"> 
<td width="6%">ID</td>
<td width="4%">选择</td>
<td width="30%">内容标题</td>
<td width="10%">更新时间</td>
<td width="11%">类目</td>
<td width="8%">点击</td>
<td width="7%">HTML</td>
<td width="10%">权限</td>
<td width="13%">属性</td>
</tr>
<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
<tr align='center' bgcolor="#FFFFFF"  onMouseMove="javascript:this.bgColor='#FCFDEE';"
	 onMouseOut="javascript:this.bgColor='#FFFFFF';" height="22"> 
<td><?php echo $fields['id']; ?></td>
<td><input name="arcID" type="checkbox" id="arcID" value="<?php echo $fields['id']; ?>" class="np"></td>
<td align='left'>
<a href='archives_do.php?aid=<?php echo $fields['id']; ?>&dopost=editArchives'><u><?php echo $fields['title']; ?></u></a>
</td>
<td><?php echo GetDateMk($fields['senddate']); ?></td>
<td><?php echo GetTypename($fields['typeid']); ?></td>
<td><?php echo $fields['click']; ?></td>
<td><?php echo IsHtmlArchives($fields['ismake']); ?></td>
<td><?php echo GetRankName($fields['arcrank']); ?></td>
<td><?php echo IsCommendArchives($fields['flag']); ?></td>
</tr>
<?php
}
}?>
<tr bgcolor="#FAFAF1"> 
<td height="24" colspan="9">
&nbsp;
<a href="javascript:selAll()" class="coolbg">全选</a> 
&nbsp;
<a href="javascript:noSelAll()" class="coolbg">取消</a> 
&nbsp;
<a href="javascript:ReturnValue()" class="coolbg">把选定值加到列表</a> 
</td>
</tr>
</form>
<tr align="right" bgcolor="#EEF4EA"> 
<td height="20" colspan="9" align="center">
	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

</td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr> 
<td height="4"></td>
</tr>
<tr bgcolor="#FFFFFF"> 
<td height="26">
<table width='100%'  border='0' cellpadding='1' cellspacing='1' bgcolor='#CBD8AC'>
   <tr bgcolor='#EEF4EA'> 
     <form name='form3' action='content_select_list.php' method='get'>
        <input type='hidden' name='f' value='<?php echo $f?>'> 
          <td background='images/wbg.gif'>
          	<table width='600' border='0' cellpadding='0' cellspacing='0'>
          	<tr>
          	<td width='90' align='center'>请选择类目：</td>
          	<td width='160'>
          <select name='cid' style='width:250px'>
          <option value='0'>选择分类...</option>
          	<?php echo $optionarr?>
          </select>
        </td>
        <td width='70'>
          关键字：
        </td>
          <td width='160'>
          	<input type='text' name='keyword' value='<?php echo $keyword?>' style='width:150'>
          </td>
          <td>
          <input name="imageField" type="image" src="images/button_search.gif" width="60" height="22" border="0" class="np">
         </td>
        </tr>
        </table>
          </td>
        </form>
        </tr>
      </table>
</td>
</tr>
<tr> 
<td colspan="2" height="4"></td>
</tr>
</table>
</td>
</tr>
</table>
</body>
</html>