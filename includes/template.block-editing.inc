<?php

/**
 * @file
 * Contains functions only needed if the user has block editing permissions.
 *
 * FROM: Zen starter theme
 */

/**
 * Add block editing variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function admin_toggle_preprocess_block_editing(&$vars, $hook) {
  $block = $vars['block'];
  
  if ($block->region == 'content') {
    return;
  }

  $vars['content'] .= '<div class="block-admin-wrapper">';
  // Display 'edit block' for custom blocks.
  $vars['content'] .= '<div class="block-config-wrapper">' . l(t('configure'), 'admin/structure/block/manage/' . $block->module . '/' . $block->delta . '/configure',
    array(
      'attributes' => array(
        'title' => t('Edit this block'),
        'class' => 'block-config',
      ),
      'query' => drupal_get_destination(),
      'html' => TRUE,
    )
  ) . '</div>';
  
  // Display 'edit view' for Views blocks.
  if ($block->module == 'views' && user_access('administer views')) {
    list($view_name, $view_block) = explode('-block', $block->delta);
    $vars['content'] .= '<div class="block-views-wrapper">' . l(t('edit view'), 'admin/build/views/edit/' . $view_name,
      array(
        'attributes' => array(
          'title' => t('edit the view that defines this block'),
          'class' => 'block-edit-view',
        ),
        'query' => drupal_get_destination(),
        'fragment' => 'views-tab-block' . $view_block,
        'html' => TRUE,
      )
    ) . '</div>';
  }
  // Display 'edit menu' for Menu blocks.
  elseif (($block->module == 'menu' || ($block->module == 'system' && $block->delta == 'user-menu')) && user_access('administer menu')) {
    $menu_name = $block->delta; //($block->module == 'user') ? 'navigation' : $block->delta;
    $vars['content'] .= '<div class="block-editting-wrapper">' . l(t('edit menu'), 'admin/structure/menu/manage/' . $menu_name . '/edit',
      array(
        'attributes' => array(
          'title' => t('edit the menu that defines this block'),
          'class' => 'block-edit-menu',
        ),
        'query' => drupal_get_destination(),
        'html' => TRUE,
      )
    ) . '</div>';
  }
  // Display 'edit menu' for Menu block blocks.
  elseif ($block->module == 'menu_block' && user_access('administer menu')) {
    list($menu_name, ) = split(':', variable_get("menu_block_{$block->delta}_parent", 'navigation:0'));
    $vars['content'] .= l('<div class="block-editting-wrapper">' . t('edit menu') . '</div>', 'admin/build/menu-customize/' . $menu_name,
      array(
        'attributes' => array(
          'title' => t('edit the menu that defines this block'),
          'class' => 'block-edit-menu',
        ),
        'query' => drupal_get_destination(),
        'html' => TRUE,
      )
    );
  }
  
  $vars['content'] .= '</div>';
}
